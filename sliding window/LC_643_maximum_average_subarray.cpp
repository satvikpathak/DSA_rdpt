#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }

        long long maxSum = sum;

        int left = 0;
        int right = k;
        while(right < nums.size()){
            sum -= nums[left];
            left++;

            sum += nums[right];
            right++;

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum/k;
    }
};

int main(){
    
    return 0;
}