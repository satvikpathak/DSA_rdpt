#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
           int start=0;
           int end=s.size()-1;
           while(start<=end){
               if(!isalnum(s[start])){start++; continue;}
               if(!isalnum(s[end])){end--;continue;}
               if(tolower(s[start])!=tolower(s[end]))return false;
               else{
                   start++;
                   end--;
               }
           }
           return true;
    }
    };

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}

// class Solution {
// public:
//     string clean(string s){
//         string newString = "";
//         char ch;
//         for(int i=0; i<s.size(); i++){
//             ch = s[i];
//             ch = tolower(ch);

//             if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
//                 newString.push_back(ch);
//             }
//         }
//         return newString;
//     }

//     bool helper(string s){
//         for(int i=0; i<s.size()/2; i++){
//             if(s[i] != s[s.size()-i-1]){
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool isPalindrome(string s) {
//         return helper(clean(s));
//     }
// };