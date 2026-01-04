// brute force
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> numsq(n);

//         for(int i=0; i<n; i++){
//             numsq[i] = nums[i]*nums[i];
//         }

//         sort(numsq.begin(), numsq.end());

//         return numsq;
//     }
// };

// optimized 2 pointer approach
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> numsq(n);

//         int left = 0;
//         int right = n-1;

//         for(int i=n-1; i>=0; i--){
//             if(abs(nums[left]) > abs(nums[right])){
//                 numsq[i] = nums[left] * nums[left];
//                 left++;
//             }

//             else{
//                 numsq[i] = nums[right] * nums[right];
//                 right--;
//             }
//         }

//         return numsq;
//     }
// };