#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int expectedSum = n * (n + 1) / 2;  // Sum from 0 to n
            int actualSum = 0;
            
            for (int i = 0; i < n; i++) {
                actualSum += nums[i];  // Sum of array elements
            }
            
            return expectedSum - actualSum;
        }
    };
    

int main() {
    vector<int> nums = {3, 0, 1};
    Solution solution;
    int missingNum = solution.missingNumber(nums);
    cout << "Missing number: " << missingNum << endl;
    return 0;
}