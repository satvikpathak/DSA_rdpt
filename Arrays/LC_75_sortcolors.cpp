#include<bits/stdc++.h>
using namespace std;

//brute force approch bubblesort (here) or any other sorting technique
// class Solution {
// public:
//     void swap(int* a, int* b){
//         int temp = *a;
//         *a = *b;
//         *b = temp;
//     }

//     void sortColors(vector<int>& nums) {
//         for(int i=0; i<nums.size(); i++){
//             for(int j=0; j<nums.size()-1; j++){
//                 if(nums[j+1]<nums[j]){
//                     swap(&nums[j+1], &nums[j]);
//                 }
//             }
//         }
//     }
// };

//3 pointer approach (Dutch National Flag Algorithm)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1){
                mid++;
            }

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
    return 0;
}