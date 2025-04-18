#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int largestElement(vector<int>& nums) {
            int largest = nums[0];
            for(int i=0; i<nums.size(); i++){
                if(nums[i]>largest) largest = nums[i];
            }
    
            return largest;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    cout << s.largestElement(nums) << endl;
    return 0;
}