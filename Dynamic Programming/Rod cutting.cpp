//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// recursively traverse and find all combinations fr each index. handle cut and not cut case. since we
//can cut rod of same length multiple times dont change the index but decrease 'N' by length of rod cut
//T.C -> O(N*N)  S.C -> O(N*N) + O(target)
//T.C(without memization) -> O(exponential) S.C->O(target)
class Solution{
  public:
  
    int solve(int i,int price[],int N,vector<vector<int>> &dp){
        if(i==0){
            return N*price[0]; //since rod at 0th index is of size 1. u divide it into remaining N pieces
        }
        if(dp[i][N]!=-1){
            return dp[i][N];
        }
        int dontCut = 0 + solve(i-1,price,N,dp);
        int cut = INT_MIN; //INT_MIN incase of not taking try it eliminate it
        int rodLength = i+1; //length of rod that we are going to cur
        if(rodLength<=N){
         cut = price[i]+solve(i,price,N-rodLength,dp); //since we can repeat the same length of cut. stay on the index
        }
        return dp[i][N]=max(dontCut,cut);
        
    }
  
    int cutRod(int price[], int n) {
        int rodLength = n;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,price,n,dp);
    }
};
