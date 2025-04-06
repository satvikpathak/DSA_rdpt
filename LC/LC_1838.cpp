#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end()); // Step 1: Sort the array
            
            long long total = 0; // Sum of current window
            int l = 0, res = 0;
    
            for (int r = 0; r < nums.size(); ++r) {
                total += nums[r];
    
                // Check if current window can be made equal to nums[r] using at most k operations
                while ((long long)nums[r] * (r - l + 1) - total > k) {
                    total -= nums[l];
                    l++;
                }
    
                res = max(res, r - l + 1);
            }
    
            return res;
        }
    };
    

int main() {
    Solution s;
    vector<int> nums = {1,2,4};
    int k = 5;
    cout << s.maxFrequency(nums, k) << endl;
    return 0;
}