#include<bits/stdc++.h>
using namespace std;

//brute
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for (int i = 0; i < n; i++) {
//             nums1[m + i] = nums2[i];
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };

//optimal
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right1 = m - 1;
        int right2 = n - 1;
        int tPtr = m + n - 1;

        while(right1 >= 0 && right2 >= 0){
            if(nums1[right1] > nums2[right2]){
                nums1[tPtr] = nums1[right1]; 
                right1--;
                tPtr--;
            }

            else{
                nums1[tPtr] = nums2[right2];
                right2--;
                tPtr--;
            }
        }

        while(right2 >= 0){
            nums1[tPtr] = nums2[right2];
            right2--;
            tPtr--;
        }
    }
};

int main(){
    
    return 0;
}