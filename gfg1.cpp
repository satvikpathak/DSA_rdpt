// Sum 1 to n Divisors

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int sumOfDivisors(int n) {
          int sum = 0;
          for(int i=0; i<n; i++){
              if(n%i==0){
                  sum = sum + i;
              }
          }
          return sum;
      }
  };

int main() {
    Solution s;
    cout<<s.sumOfDivisors(10);
    return 0;
}