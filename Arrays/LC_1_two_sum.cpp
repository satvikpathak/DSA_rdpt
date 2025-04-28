#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mpp;
            for(int i=0; i<nums.size(); i++){
                int a = nums[i];
                int more = target - a;
                if(mpp.find(more) != mpp.end()){
                    return {mpp[more], i};
                }
                mpp[a] = i;
            }
            return {};
        }
    };

int main() {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = s.twoSum(nums, target);
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    return 0;
}