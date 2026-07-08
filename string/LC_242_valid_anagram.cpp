#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> mpp;

        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }

        for (auto [key, val] : mpp) {
            if (val != 0) return false;
        }

        return true;
        
    }
};

int main(){
    
    return 0;
}