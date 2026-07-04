#include<bits/stdc++.h>
using namespace std;


//O(n) solution
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for(int i = 0; i<nums.size(); i++){
//             if(nums[i] == target){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

//O(logn)
//expected solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left<=right){
            int mid = left + (right - left) /2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] < target){
                left = mid + 1;
            }

            else right = mid - 1;
        }

        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7};
    int target = 6;
    int ans = s.search(nums,target);
    cout<<ans;
    return 0;
}