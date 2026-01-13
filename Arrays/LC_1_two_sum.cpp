#include<bits/stdc++.h>
using namespace std;


//better approach using map(if i have to return indices, this is best but if only yes/no then use two pointer since no storing indices needed)
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

//brute force approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }
};