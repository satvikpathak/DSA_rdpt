#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int index = nums.size() - 1;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                ans[index] = nums[left] * nums[left];
                left++;
            }

            else {
                ans[index] = nums[right] * nums[right];
                right --;
            }
            index --;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}