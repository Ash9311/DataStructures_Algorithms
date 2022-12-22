//recursively explore all possibilities. we have an option of buying ans selling. inside buying we have an option holding it too
//invert the 'buy' parameter as u buy or sell. even in sell there are 2 options and u take the max of those option's possibilities.
//without memoization TC -> O(2^n) (since we have option of buying or selling) SC->O(N) (aux stack space)
//with memo- TC->O(N*2)  SC->O(N*2)+O(N)
class Solution {
public:
    
    int solve(int i,vector<int>& prices,int buy,vector<vector<int>> &dp){
        if(i==prices.size()){ //if days expired and u havent sold ur stock then its 0
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        long profit =0;
        if(buy){ //even if u can buy u have liberty of not picking it
            int buy = -prices[i]+solve(i+1,prices,0,dp);
            int notBuy = solve(i+1,prices,1,dp);
             profit = max(buy,notBuy);
        }
        else{ //sell case
            int sell = prices[i] + solve(i+1,prices,1,dp); //change state to 1 so that u are eligible to buy
            int dontSell = 0 + solve(i+1,prices,0,dp);
             profit = max(sell,dontSell);
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int buy = 1; //initially u can buy 
        return solve(0,prices,buy,dp);
    }
};
