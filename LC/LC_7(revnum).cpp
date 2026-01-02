#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int reversedNum = 0;
            while (x != 0) {
                int last_digit = x % 10;
                 if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && last_digit > 7)) return 0;
                if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && last_digit < -8)) return 0;
                reversedNum = reversedNum * 10 + last_digit;
                x /= 10;
            }
            return reversedNum;
        }
    };

int main() {
    Solution s;
    int x;
    cin>>x;
    cout<<s.reverse(x);
    return 0;
}