//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

//recursively explore all possibilities. we have an option of buying or selling. inside buying we have an option holding it too
//invert the 'buy' parameter as u buy or sell. even in sell there are 2 options and u take the max of those option's possibilities.
//we have a 1 day cooldown condition so after selling go to i+2th day
class Solution {
public:

    int solve(int i,vector<int>& prices,int buy,vector<vector<int>> &dp){
        if(i>=prices.size()){//>= bcz i can go out of bound since v r having i+2
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        long profit = 0;

        if(buy){
            int buy = -prices[i] + solve(i+1,prices,0,dp); //since u r buying price is in -ve
            int dontBuy = solve(i+1,prices,1,dp); // we didnt buy,day has passed. so cool down is done
            profit = max(buy,dontBuy);
        }
        else{
            int sell = prices[i] + solve(i+2,prices,1,dp); //IF WE SELL, then there comes a coolDown of 1 day. so go to i+2
            int dontSell = solve(i+1,prices,0,dp);
            profit = max(sell,dontSell);
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n,vector<int>(2,-1)); //declare a 2d dp
        return solve(0,prices,buy,dp);
    }
};
