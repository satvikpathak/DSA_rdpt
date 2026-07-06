#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int right = 0;
        int minLength = INT_MAX;
        
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left ++;
            }
            right ++;
        }

        if(minLength == INT_MAX) return 0;
        else return minLength;
    }
};

int main(){
    
    return 0;
}