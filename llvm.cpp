#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include <queue>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace llvm;

#define DEBUG_TYPE "taint-analysis"

STATISTIC(NumTaintedValues, "Number of tainted values identified");
STATISTIC(NumVulnerabilities, "Number of vulnerabilities detected");

namespace {

// Class to represent a taint source with additional information
struct TaintSource {
  Value* SourceValue;
  StringRef SourceKind;
  unsigned LineNumber;
  
  TaintSource(Value* V, StringRef Kind, unsigned LineNum)
    : SourceValue(V), SourceKind(Kind), LineNumber(LineNum) {}
};

// Class to represent a detected vulnerability
struct Vulnerability {
  Value* TaintedValue;
  Value* SinkValue;
  StringRef SinkKind;
  TaintSource Source;
  unsigned LineNumber;
  
  Vulnerability(Value* TV, Value* SV, StringRef SK, TaintSource Src, unsigned LineNum)
    : TaintedValue(TV), SinkValue(SV), SinkKind(SK), Source(Src), LineNumber(LineNum) {}
};

// Custom hash function for TaintSource
struct TaintSourceHash {
  std::size_t operator()(const TaintSource& TS) const {
    return std::hash<const void*>()(TS.SourceValue);
  }
};

// Custom equality function for TaintSource
struct TaintSourceEqual {
  bool operator()(const TaintSource& TS1, const TaintSource& TS2) const {
    return TS1.SourceValue == TS2.SourceValue;
  }
};

class TaintAnalysisPass : public FunctionPass {
public:
  static char ID;
  TaintAnalysisPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override;
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
    AU.addRequired<AAResultsWrapperPass>();
  }

private:
  // Maps tainted values to their sources
  std::unordered_map<Value*, std::unordered_set<TaintSource, TaintSourceHash, TaintSourceEqual>> TaintedValues;
  
  // List of vulnerabilities detected
  std::vector<Vulnerability> Vulnerabilities;
  
  // Set of sanitized values
  std::unordered_set<Value*> SanitizedValues;
  
  // Helper methods
  void identifyTaintSources(Function &F);
  void propagateTaint(Function &F);
  void detectVulnerabilities(Function &F);
  bool isSource(Instruction &I);
  bool isSink(Instruction &I);
  bool isSanitizer(Instruction &I);
  void addTaint(Value *V, TaintSource Source);
  void handleCallInst(CallInst &CI);
  void handleLoadInst(LoadInst &LI);
  void handleStoreInst(StoreInst &SI);
  void printResults(Function &F);
  bool isVulnerable(Value *TaintedVal, Value *SinkVal, StringRef SinkKind);
  unsigned getLineNumber(Instruction &I);
};

char TaintAnalysisPass::ID = 0;

bool TaintAnalysisPass::runOnFunction(Function &F) {
  errs() << "Running Taint Analysis on function: " << F.getName() << "\n";
  
  // Clear previous results
  TaintedValues.clear();
  Vulnerabilities.clear();
  SanitizedValues.clear();
  
  // Step 1: Identify taint sources
  identifyTaintSources(F);
  
  // Step 2: Propagate taint
  propagateTaint(F);
  
  // Step 3: Detect vulnerabilities
  detectVulnerabilities(F);
  
  // Step 4: Print results
  printResults(F);
  
  // This pass is an analysis pass, so it doesn't modify the function
  return false;
}

void TaintAnalysisPass::identifyTaintSources(Function &F) {
  for (auto &BB : F) {
    for (auto &I : BB) {
      if (isSource(I)) {
        // For call instructions that are taint sources
        if (auto *CI = dyn_cast<CallInst>(&I)) {
          StringRef FuncName = CI->getCalledFunction() ? CI->getCalledFunction()->getName() : "";
          
          if (FuncName == "scanf" || FuncName == "fscanf") {
            // For scanf, the tainted value is the destination (2nd+ argument)
            for (unsigned i = 1; i < CI->getNumArgOperands(); ++i) {
              if (auto *DestPtr = dyn_cast<Value>(CI->getArgOperand(i))) {
                addTaint(DestPtr, TaintSource(DestPtr, "input_func", getLineNumber(I)));
              }
            }
          } else if (FuncName == "fgets" || FuncName == "gets") {
            // For fgets/gets, the tainted value is the buffer (1st argument)
            if (auto *DestPtr = dyn_cast<Value>(CI->getArgOperand(0))) {
              addTaint(DestPtr, TaintSource(DestPtr, "input_func", getLineNumber(I)));
            }
          } else if (FuncName == "read" || FuncName == "recv") {
            // For read/recv, the tainted value is the buffer (2nd argument)
            if (auto *DestPtr = dyn_cast<Value>(CI->getArgOperand(1))) {
              addTaint(DestPtr, TaintSource(DestPtr, "input_func", getLineNumber(I)));
            }
          } else if (FuncName == "getenv") {
            // getenv returns tainted data
            addTaint(CI, TaintSource(CI, "env_input", getLineNumber(I)));
          }
        }
      }
    }
  }
  
  // Handle function arguments that might be tainted
  // In a real implementation, this would be informed by interprocedural analysis
  // For this project, we conservatively consider external function parameters as tainted
  if (F.hasExternalLinkage()) {
    for (auto &Arg : F.args()) {
      if (Arg.getType()->isPointerTy()) {
        addTaint(&Arg, TaintSource(&Arg, "external_input", 0));
      }
    }
  }
  
  errs() << "Identified " << TaintedValues.size() << " initial taint sources\n";
}

void TaintAnalysisPass::propagateTaint(Function &F) {
  std::queue<Value*> WorkList;
  std::unordered_set<Value*> Visited;
  
  // Initialize worklist with tainted values
  for (auto &Entry : TaintedValues) {
    WorkList.push(Entry.first);
  }
  
  while (!WorkList.empty()) {
    Value *V = WorkList.front();
    WorkList.pop();
    
    // Skip if already processed
    if (Visited.count(V)) continue;
    Visited.insert(V);
    
    // Process all uses of the tainted value
    for (auto &U : V->uses()) {
      User *User = U.getUser();
      
      if (auto *I = dyn_cast<Instruction>(User)) {
        // Check if this is a sanitizer
        if (isSanitizer(*I)) {
          SanitizedValues.insert(I);
          continue;
        }
        
        // Handle different instruction types
        if (auto *CI = dyn_cast<CallInst>(I)) {
          handleCallInst(*CI);
        } else if (auto *LI = dyn_cast<LoadInst>(I)) {
          handleLoadInst(*LI);
        } else if (auto *SI = dyn_cast<StoreInst>(I)) {
          handleStoreInst(*SI);
        } else if (auto *BO = dyn_cast<BinaryOperator>(I)) {
          // Taint is propagated through binary operations
          if (TaintedValues.count(V)) {
            addTaint(BO, *(TaintedValues[V].begin()));
            WorkList.push(BO);
          }
        } else if (auto *GEP = dyn_cast<GetElementPtrInst>(I)) {
          // Taint is propagated through GEP instructions
          if (TaintedValues.count(V)) {
            addTaint(GEP, *(TaintedValues[V].begin()));
            WorkList.push(GEP);
          }
        } else if (auto *Cast = dyn_cast<CastInst>(I)) {
          // Taint is propagated through casts
          if (TaintedValues.count(V)) {
            addTaint(Cast, *(TaintedValues[V].begin()));
            WorkList.push(Cast);
          }
        } else if (auto *PHI = dyn_cast<PHINode>(I)) {
          // Taint is propagated through PHI nodes
          if (TaintedValues.count(V) && !TaintedValues.count(PHI)) {
            addTaint(PHI, *(TaintedValues[V].begin()));
            WorkList.push(PHI);
          }
        }
        // Add more instruction handlers as needed
      }
    }
  }
  
  errs() << "After propagation, identified " << TaintedValues.size() << " tainted values\n";
  NumTaintedValues = TaintedValues.size();
}

void TaintAnalysisPass::handleCallInst(CallInst &CI) {
  Function *F = CI.getCalledFunction();
  if (!F) return; // Skip indirect calls for simplicity
  
  StringRef FuncName = F->getName();
  
  // Handle function calls that propagate taint
  // This is a simplified model; a real implementation would use function summaries
  
  bool TaintedArgument = false;
  Value *TaintedArg = nullptr;
  TaintSource Source("", 0);
  
  // Check if any argument is tainted
  for (unsigned i = 0; i < CI.getNumArgOperands(); ++i) {
    Value *Arg = CI.getArgOperand(i);
    if (TaintedValues.count(Arg)) {
      TaintedArgument = true;
      TaintedArg = Arg;
      Source = *(TaintedValues[Arg].begin());
      break;
    }
  }
  
  // If any argument is tainted, check if this function propagates taint
  if (TaintedArgument) {
    // Functions that copy data and propagate taint
    if (FuncName == "strcpy" || FuncName == "strncpy" || FuncName == "memcpy" ||
        FuncName == "memmove" || FuncName == "strcat" || FuncName == "strncat") {
      // For copy functions, the destination (first argument) becomes tainted
      Value *Dest = CI.getArgOperand(0);
      addTaint(Dest, Source);
    }
    // Functions that return data based on inputs
    else if (FuncName == "strdup" || FuncName == "strndup") {
      // Return value is tainted
      addTaint(&CI, Source);
    }
    // For other functions, we conservatively consider return value tainted 
    // if any argument is tainted
    else if (!F->getReturnType()->isVoidTy()) {
      addTaint(&CI, Source);
    }
  }
}

void TaintAnalysisPass::handleLoadInst(LoadInst &LI) {
  // If the pointer operand is tainted, the loaded value is tainted
  Value *Ptr = LI.getPointerOperand();
  if (TaintedValues.count(Ptr)) {
    for (auto &Source : TaintedValues[Ptr]) {
      addTaint(&LI, Source);
    }
  }
}

void TaintAnalysisPass::handleStoreInst(StoreInst &SI) {
  // If the value being stored is tainted, the location becomes tainted
  Value *Val = SI.getValueOperand();
  Value *Ptr = SI.getPointerOperand();
  
  if (TaintedValues.count(Val)) {
    for (auto &Source : TaintedValues[Val]) {
      addTaint(Ptr, Source);
    }
  }
}

void TaintAnalysisPass::detectVulnerabilities(Function &F) {
  for (auto &BB : F) {
    for (auto &I : BB) {
      if (isSink(I)) {
        // Check if this sink uses tainted data
        for (unsigned i = 0; i < I.getNumOperands(); ++i) {
          Value *Op = I.getOperand(i);
          
          if (TaintedValues.count(Op) && !SanitizedValues.count(Op)) {
            // This is a potential vulnerability
            auto *CI = dyn_cast<CallInst>(&I);
            StringRef SinkType = CI ? (CI->getCalledFunction() ? CI->getCalledFunction()->getName() : "unknown_call") : "memory_access";
            
            for (auto &Source : TaintedValues[Op]) {
              if (isVulnerable(Op, &I, SinkType)) {
                Vulnerability V(Op, &I, SinkType, Source, getLineNumber(I));
                Vulnerabilities.push_back(V);
                NumVulnerabilities++;
              }
            }
          }
        }
      }
    }
  }
}

bool TaintAnalysisPass::isSource(Instruction &I) {
  // Check if this instruction is a taint source
  if (auto *CI = dyn_cast<CallInst>(&I)) {
    if (CI->getCalledFunction()) {
      StringRef FuncName = CI->getCalledFunction()->getName();
      
      // Common input functions
      if (FuncName == "scanf" || FuncName == "fscanf" ||
          FuncName == "gets" || FuncName == "fgets" ||
          FuncName == "read" || FuncName == "recv" ||
          FuncName == "getenv") {
        return true;
      }
    }
  }
  
  return false;
}

bool TaintAnalysisPass::isSink(Instruction &I) {
  // Check if this instruction is a potential vulnerability sink
  if (auto *CI = dyn_cast<CallInst>(&I)) {
    if (CI->getCalledFunction()) {
      StringRef FuncName = CI->getCalledFunction()->getName();
      
      // Memory manipulation functions that can cause buffer overflows
      if (FuncName == "strcpy" || FuncName == "strcat" ||
          FuncName == "sprintf" || FuncName == "vsprintf") {
        return true;
      }
      
      // Command execution functions that can lead to command injection
      if (FuncName == "system" || FuncName == "popen" ||
          FuncName == "execl" || FuncName == "execlp" ||
          FuncName == "execle" || FuncName == "execv" ||
          FuncName == "execvp" || FuncName == "execvpe") {
        return true;
      }
    }
  }
  
  // Memory access that could be vulnerable if index is tainted
  if (auto *GEP = dyn_cast<GetElementPtrInst>(&I)) {
    for (unsigned i = 1; i < GEP->getNumOperands(); ++i) {
      if (TaintedValues.count(GEP->getOperand(i))) {
        return true;
      }
    }
  }
  
  return false;
}

bool TaintAnalysisPass::isSanitizer(Instruction &I) {
  // Simple sanitizer detection: check if a tainted value is used in a comparison
  if (auto *ICmp = dyn_cast<ICmpInst>(&I)) {
    for (unsigned i = 0; i < ICmp->getNumOperands(); ++i) {
      Value *Op = ICmp->getOperand(i);
      if (TaintedValues.count(Op)) {
        // This is a potential sanitizer, but a real implementation would check
        // that the comparison is actually used to guard sensitive operations
        return true;
      }
    }
  }
  
  // Simple sanitization through functions like isalnum, isdigit, etc.
  if (auto *CI = dyn_cast<CallInst>(&I)) {
    if (CI->getCalledFunction()) {
      StringRef FuncName = CI->getCalledFunction()->getName();
      
      // Character validation functions
      if (FuncName.startswith("is") && 
          (FuncName == "isalnum" || FuncName == "isalpha" || 
           FuncName == "isdigit" || FuncName == "isspace")) {
        return true;
      }
    }
  }
  
  return false;
}

void TaintAnalysisPass::addTaint(Value *V, TaintSource Source) {
  // Add taint to a value
  if (!TaintedValues[V].count(Source)) {
    TaintedValues[V].insert(Source);
  }
}

bool TaintAnalysisPass::isVulnerable(Value *TaintedVal, Value *SinkVal, StringRef SinkKind) {
  // Determine if this is a genuine vulnerability based on the context
  // This is a simplified check; a real implementation would be more sophisticated
  
  // Memory functions with tainted size/length are vulnerable
  if (SinkKind == "strcpy" || SinkKind == "memcpy" || SinkKind == "strcat") {
    CallInst *CI = dyn_cast<CallInst>(SinkVal);
    if (CI && CI->getArgOperand(1) == TaintedVal) {
      return true;
    }
  }
  
  // Command execution with tainted command is vulnerable
  if (SinkKind == "system" || SinkKind == "popen" || 
      SinkKind.startswith("exec")) {
    CallInst *CI = dyn_cast<CallInst>(SinkVal);
    if (CI && CI->getArgOperand(0) == TaintedVal) {
      return true;
    }
  }
  
  // Array access with tainted index is vulnerable
  if (SinkKind == "memory_access") {
    GetElementPtrInst *GEP = dyn_cast<GetElementPtrInst>(SinkVal);
    if (GEP) {
      for (unsigned i = 1; i < GEP->getNumOperands(); ++i) {
        if (GEP->getOperand(i) == TaintedVal) {
          return true;
        }
      }
    }
  }
  
  return false;
}

unsigned TaintAnalysisPass::getLineNumber(Instruction &I) {
  // Get source line number for an instruction
  const DILocation *DIL = I.getDebugLoc();
  if (DIL) {
    return DIL->getLine();
  }
  return 0;
}

void TaintAnalysisPass::printResults(Function &F) {
  errs() << "=== Taint Analysis Results for " << F.getName() << " ===\n";
  errs() << "Identified " << TaintedValues.size() << " tainted values\n";
  errs() << "Detected " << Vulnerabilities.size() << " potential vulnerabilities\n\n";
  
  // Print detailed vulnerability information
  for (auto &V : Vulnerabilities) {
    errs() << "VULNERABILITY: ";
    
    if (V.SinkKind == "strcpy" || V.SinkKind == "strcat" || 
        V.SinkKind == "memcpy" || V.SinkKind == "memmove") {
      errs() << "Buffer Overflow";
    } else if (V.SinkKind == "system" || V.SinkKind == "popen" || 
               V.SinkKind.startswith("exec")) {
      errs() << "Command Injection";
    } else if (V.SinkKind == "memory_access") {
      errs() << "Memory Corruption";
    } else {
      errs() << "General Vulnerability";
    }
    
    errs() << " at line " << V.LineNumber << "\n";
    errs() << "  Tainted value ";
    V.TaintedValue->printAsOperand(errs(), false);
    errs() << " from source ";
    V.Source.SourceValue->printAsOperand(errs(), false);
    errs() << " (" << V.Source.SourceKind << " at line " 
           << V.Source.LineNumber << ")\n";
    errs() << "  Used in sink ";
    V.SinkValue->printAsOperand(errs(), false);
    errs() << " (" << V.SinkKind << ")\n\n";
  }
}

// Register the pass
static RegisterPass<TaintAnalysisPass> X("taint-analysis", "Static Taint Analysis Pass");

// Register the pass to be run by opt
static void registerTaintAnalysisPass(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
  PM.add(new TaintAnalysisPass());
}

static RegisterStandardPasses RegisterPass(PassManagerBuilder::EP_EarlyAsPossible,
 registerTaintAnalysisPass);