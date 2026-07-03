#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;

        for (int num : nums) {
            if (cnt == 0) {
                candidate = num;
            }

            if (num == candidate) {
                cnt++;
            } else {
                cnt--;
            }
        }

        return candidate;
    }
};


int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution sol;
    cout << sol.majorityElement(nums) << endl;    
    return 0;
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        
        for(int i = 0; i < nums.size(); i++){
            // Increase the count for this specific number
            counts[nums[i]]++; 
            
            // Check if this specific number's count has crossed the threshold
            if(counts[nums[i]] > nums.size() / 2){
                return nums[i];
            }
        }
        return 0; 
    }
};