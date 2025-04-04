#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int cnt = 1;
      void printNos(int n) {
          while(cnt <= n){
              cout<<cnt<<" ";
              cnt ++;
              printNos(n);
          }
      }
  };

int main() {
    Solution s;
    s.printNos(5);
    return 0;
}