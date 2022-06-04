//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

make a note of lowest price and track the difference in all iterations

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = 0;
        int lowest = INT_MAX;
        for(int i=0;i<prices.size();i++){
                if(prices[i]<lowest){
                    lowest = prices[i];
                }
                maxx = max(prices[i]-lowest,maxx);
        }
        return maxx;
    }
};
