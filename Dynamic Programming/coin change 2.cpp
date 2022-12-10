//https://leetcode.com/problems/coin-change-ii/description/
//recursive traverse through all the indexes but this problem is quiet different here since we can pick the same coin multiple times
//we can stay on the same index after we pick .we wont be stuck there since target reduces as we pick coins. so recursion will go too deeply
//it finds all the combinations
class Solution {
public:
//T.C -> O(n*amount) S.C->O(n*amount) + O(amount) (recursion aux space is huge coz v stay on same index. )
//witout memoization - >T.C -> much greater than(O(2^n))  S.C->O(target)
int solve(int i,vector<int>& coins, int amount,vector<vector<int>> &dp){
      
        if(i==0){ //if on the last index, just check if all of those coins if divisible
           if(amount%coins[i]==0){
               return 1; //its a +1 count to this combination
           }
           return 0;
            }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int notPick = solve(i-1,coins,amount,dp);
        int pick = 0;
        if(coins[i]<=amount){ //boundary check
            pick =  solve(i,coins,amount-coins[i],dp); //add 1 since we are finding the count of coins. staying on same index since we have infinite supply, we can multiple use it
        }

        return dp[i][amount]=pick+notPick; //since we need count add it up
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,coins,amount,dp);
        return ans;
    }
    
};
