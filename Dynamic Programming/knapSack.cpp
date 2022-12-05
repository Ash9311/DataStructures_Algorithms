//recursively traverse through all possibilities on each index. handle the 0th index and pick and not pick case.
//T.C->O(n*maxWeight)  S.C-> O(n*maxWeight) + O(n)
#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>> &dp){
    if(n==0){//when at last iteration pick if u can since there is no moving forward
        if(weight[0]<=maxWeight){
            return value[0];
        }
        return 0;
    }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    int notPick = 0 + solve(weight,value,n-1,maxWeight,dp); //we have option of picking or not picking
    int pick = 0;
    if(weight[n]<=maxWeight){ //boundary condition: must have space before stealing
        pick=value[n]+solve(weight,value,n-1,maxWeight-weight[n],dp);
    }
    return dp[n][maxWeight]=max(pick,notPick); //since we need the max;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)); 
	return solve(weight,value,n-1,maxWeight,dp);
}


--------------------------------------
//java some other question
class Solution 
{ 
    //Function to return max value that can be put in knapsack of capacity W.
    static int knapSack(int W, int wt[], int val[], int n) 
    { 
         // your code here 
         if(n==0||W==0){
             return 0;
         }
         
         if(wt[n-1]>W){
             return knapSack(W,wt,val,n-1);
             
         }
         
         else{
             return Math.max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
         }
    } 
}


