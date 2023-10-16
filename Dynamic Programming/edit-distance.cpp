//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m  = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n,m,dp);
    }

    int solve(string word1,string word2,int n,int m,vector<vector<int>>&dp){
      
        if(n<=0) return m;
        if(m<=0) return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(word1[n-1]==word2[m-1]) return solve(word1,word2,n-1,m-1,dp); //if both match then proceed further
        int insert =  solve(word1,word2,n,m-1,dp); //explore all possible combination of operations
        int del =  solve(word1,word2,n-1,m,dp);
        int replace =  solve(word1,word2,n-1,m-1,dp);
        
        return dp[n][m]=1+min(min(insert,del),replace); //add +1 since v r chosing a min most operation
        

    }
};
