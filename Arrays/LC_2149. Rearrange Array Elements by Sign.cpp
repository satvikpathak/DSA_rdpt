#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0; int negIndex = 1;

        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex +=2;
            }

            else{
                ans[posIndex] = nums[i];
                posIndex +=2;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums{-1,1,-2,2,-3,3,-4,4};
    Solution sol;
    vector<int> ans = sol.rearrangeArray(nums);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}