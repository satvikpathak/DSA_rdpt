// Frequencies in a Limited Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);  // Initialize result array with zeros

        for (int i = 0; i < n; i++) {
            if (arr[i] >= 1 && arr[i] <= n) {
                result[arr[i] - 1]++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> result = s.frequencyCount(arr);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
