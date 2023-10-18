//https://leetcode.com/problems/distinct-subsequences/
class Solution {
public:

    int solve(string &s,string &t,int i,int j,int n,int m, vector<vector<int>> &dp){
        if(j==m) return 1;//all char in t is matched in s
        if(i==n) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
        int ways = 0;
        if(s[i]==t[j])  ways+=solve(s,t,i+1,j+1,n,m,dp); //if its a match. consider it and move both forward.
        ways+=solve(s,t,i+1,j,n,m,dp); //if its not a match move i forward. even if its a match we can compute other combinations
        return dp[i][j]=ways;

    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,0,0,s.size(),t.size(),dp);
    }
};
