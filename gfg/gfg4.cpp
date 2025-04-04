//reverse an array using recursion

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void reverseArray(vector<int> &arr, int l, int r) {
          if (l >= r) return;
  
          swap(arr[l], arr[r]);
  
          reverseArray(arr, l + 1, r - 1);
      }
  
      void reverseArray(vector<int> &arr) {
          reverseArray(arr, 0, arr.size() - 1);
      }
  };

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    s.reverseArray(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}