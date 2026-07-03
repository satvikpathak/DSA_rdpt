#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i=0; i<nums.size(); i++){
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> v = {1, 2, 3, 1};
    
    // Call the correct function and store the result
    bool hasDuplicate = s.containsDuplicate(v);
    
    // Print the result to the terminal
    if (hasDuplicate) {
        cout << "Duplicate found!" << endl;
    } else {
        cout << "No duplicates." << endl;
    }
    
    return 0;
}