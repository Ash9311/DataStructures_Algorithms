//https://leetcode.com/problems/coin-change/description/
//recursive traverse through all the indexes but this problem is quiet different here since we can pick the same coin multiple times
//we can stay on the same index after we pick .we wont be stuck there since target reduces as we pick coins. so recursion will go too deeply
//it finds all the combinations

//T.C -> O(n*amount) S.C->O(n*amount) + O(amount) (recursion aux space is huge coz v stay on same index. )
//witout memoization - >T.C -> much greater than(O(2^n))  S.C->O(target)
class Solution {
public:

    int solve(int i,vector<int>& coins, int amount,vector<vector<int>> &dp){
      
        if(i==0){ //if on the last index, just return all of those coins if divisible
           if(amount%coins[i]==0){
               return amount/coins[i];
           }
           return 1e9;
            }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int notPick = 0 + solve(i-1,coins,amount,dp);
        int pick = INT_MAX;
        if(coins[i]<=amount){ //boundary check
            pick = 1 + solve(i,coins,amount-coins[i],dp); //add 1 since we are finding the count of coins. staying on same index since we have infinite supply, we can multiple use it
        }

        return dp[i][amount]=min(pick,notPick); //since we are hunting min coins
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,coins,amount,dp);
        if(ans>=1e9){ //conditions from statement
            return -1;
        }
        return ans;
    }
};
