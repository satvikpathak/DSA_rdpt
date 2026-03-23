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