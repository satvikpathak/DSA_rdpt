#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            int largest = nums[0];
            int slargest = -1;
    
            for(int i=0; i<nums.size(); i++){
                if(nums[i] > largest){
                    slargest = largest;
                    largest = nums[i];
                }
    
                else if(nums[i] < largest && nums[i] > slargest){
                    slargest = nums[i];
                }
            }
    
            return slargest;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {10,10,10,10};
    cout << s.secondLargestElement(nums) << endl;
    return 0;
}