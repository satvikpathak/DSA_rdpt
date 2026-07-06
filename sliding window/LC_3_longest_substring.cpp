#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        unordered_set<char> seen;
        while(right < s.size()){
            while(seen.find(s[right]) != seen.end()){
                seen.erase(s[left]);
                left ++;
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right -left + 1);
            right ++;
        }

        return maxLength;
    }
};  

int main(){
    
    return 0;
}