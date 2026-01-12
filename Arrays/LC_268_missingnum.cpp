#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int expectedSum = n * (n + 1) / 2;  // Sum from 0 to n
            int actualSum = 0;
            
            for (int i = 0; i < n; i++) {
                actualSum += nums[i];  // Sum of array elements
            }
            
            return expectedSum - actualSum;
        }
    };
    

int main() {
    vector<int> nums = {3, 0, 1};
    Solution solution;
    int missingNum = solution.missingNumber(nums);
    cout << "Missing number: " << missingNum << endl;
    return 0;
}


//brute force
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++){ // Changed to <=
            int flag = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    flag++;
                    break; // Optimization: stop searching once found
                }
            }
            if(flag == 0) return i;
        }
        return -1; // Should never reach here
    }
};