// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
//     public:
//         bool isPalindrome(int x) {
//             int palindrome = 0;
//             int y=x;

//             if(x < 0) return false;

//             while(x != 0) {
//                 int last_digit = x % 10;
//                 palindrome = palindrome * 10 + last_digit;
//                 x /= 10;
//             }
//             return (palindrome == y);
//         }
//     };

// int main() {
//     Solution s;
//     cout<<s.isPalindrome(123);
//     return 0;
// }

class Solution {
public:
    bool isPalindrome(int x) {
        long int revnum = 0;
        int y = x;
        if(x<0){
            return false;
        }
        while(x != 0){
            int ld=x%10;
            revnum = revnum*10 + ld;
            x=x/10;
        }
        return revnum == y;
    }
};