//Factorials <= n

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<long long> factorialNumbers(long long n) {
          vector<long long> result;
          long long fact = 1;
          int i = 1;
  
          while (fact <= n) {
              result.push_back(fact);
              i++;
              fact *= i;
          }
  
          return result;
      }
  };

int main() {
    Solution s;
    long long n;
    cin >> n;
    vector<long long> result = s.factorialNumbers(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}