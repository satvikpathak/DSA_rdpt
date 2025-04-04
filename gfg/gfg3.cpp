#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int cnt = 1;
      void printGfg(int N) {
          while(cnt<=N){
              cout<<"GFG ";
              cnt ++;
              printGfg(N);
          }
      }
  };
  

int main() {
    Solution s;
    s.printGfg(5);
    return 0;
}