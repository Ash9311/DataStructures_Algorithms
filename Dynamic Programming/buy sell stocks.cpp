//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//in each iteration calculate the cost if u sell being purchased at mini. and update mini,maxprofit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            int cost = prices[i]-mini;
            mini = min(mini,prices[i]);
            maxProfit = max(maxProfit,cost);
        }
        return maxProfit;
    }
};
