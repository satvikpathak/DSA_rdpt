#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            int palindrome = 0;
            int y=x;

            if(x < 0) return false;

            while(x != 0) {
                int last_digit = x % 10;
                palindrome = palindrome * 10 + last_digit;
                x /= 10;
            }
            return (palindrome == y);
        }
    };

int main() {
    Solution s;
    cout<<s.isPalindrome(123);
    return 0;
}