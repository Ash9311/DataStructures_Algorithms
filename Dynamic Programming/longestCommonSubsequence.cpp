//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// function to find longest common subsequence
//start with last indexes of both strings.recursively explore all indexes. if string index is a match move both indexes 1 step back.
//if string isnt a match then split it into two cases. where index of 1 string is not moved and other is moved. and return the max of those
class Solution
{
    public:
    
    int solve(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return 1+solve(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp)); //if not a match then split to two cases and return the max
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,s1,s2,dp);
    }
};
