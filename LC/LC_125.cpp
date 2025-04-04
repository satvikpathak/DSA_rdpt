#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string cleaned = "";
            
            // Remove non-alphanumeric characters and convert to lowercase
            for (char c : s) {
                if (isalnum(c)) {
                    cleaned += tolower(c);
                }
            }
    
            // Two-pointer approach to check palindrome
            int left = 0, right = cleaned.size() - 1;
            while (left < right) {
                if (cleaned[left] != cleaned[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    };

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama");
    
    return 0;
}