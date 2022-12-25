//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//recursively explore all possibilities. we have an option of buying ans selling. inside buying we have an option holding it too
//invert the 'buy' parameter as u buy or sell. even in sell there are 2 options and u take the max of those option's possibilities. decerement 
//limit when the stock is sold i.e the transaction is completed
class Solution {
public:

    //TC- O(N*2*K)  SC- O(N*2*K)+O(N)
     int solve(int i,vector<int>& prices,int buy,int limit,vector<vector<vector<int>>> &dp){
        if(i==prices.size()||limit==0){ //if days expired and u havent sold ur stock then its 0, or if limit of transaction is done
            return 0;
        }
        if(dp[i][buy][limit]!=-1){
            return dp[i][buy][limit];
        }
        long profit =0;
        if(buy){ //even if u can buy u have liberty of not picking it
            int buy = -prices[i]+solve(i+1,prices,0,limit,dp);
            int notBuy = solve(i+1,prices,1,limit,dp);
             profit = max(buy,notBuy);
        }
        else{ //sell case
            int sell = prices[i] + solve(i+1,prices,1,limit-1,dp); //change state to 1 so that u are eligible to buy, decrement the limit when u sell
            int dontSell = 0 + solve(i+1,prices,0,limit,dp);
             profit = max(sell,dontSell);
        }
        return dp[i][buy][limit]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))); //declare a 3d dp
        int buy = 1; //initially u can buy 
        int limit=k;
        return solve(0,prices,buy,limit,dp);
    }
};
