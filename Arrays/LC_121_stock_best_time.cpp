#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            int cost = prices[i] - minimum;
            profit = max(profit, cost);
            minimum = min(minimum, prices[i]);
        }

        return profit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
    return 0;
}