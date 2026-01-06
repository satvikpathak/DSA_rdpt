#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int count = 0;
            int n = nums.size();
            
            for (int i = 0; i < n; ++i) {
                if (nums[i] > nums[(i + 1) % n]) {
                    ++count;
                }
                if (count > 1) {
                    return false;
                }
            }
            
            return true;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << s.check(nums) << endl;
    return 0;
}


// class Solution {
// public:
    // bool check(vector<int>& nums) {
        // int n = nums.size();
        // int cnt = 0;
// 
        // for(int i=0; i<n; i++){
            // if(nums[i]>nums[(i+1) % n]){
                // cnt++;
            // }
// 
            // if(cnt > 1) return false;
        // }
// 
        // return true;
    // }
// };