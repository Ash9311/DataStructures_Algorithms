//https://leetcode.com/problems/delete-operation-for-two-strings/description/
//lets take example of converting 'abcd' to 'anc' .so the longest common subsequence is 'ac' so we need to delete 2 char from 'abcd'. and then
// insert 1 char to 'ac'(i.e 'n') inorder to convert it into 'anc'
//so deletion = n - length(LCS)
// inserttion = m - length(LCS)
//n and m are size of 2 strings
//ans = (n+m) - 2*(length(LCS))

//start with last indexes of both strings.recursively explore all indexes. if string index is a match move both indexes 1 step back.
//if string isnt a match then split it into two cases. where index of 1 string is not moved and other is moved. and return the max of those
class Solution {
public:
	 int ans=0;
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
        return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp)); //if not a match then split to two cases where index is moved in either and return the max
    }
    int longestCommonSubseq(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,s1,s2,dp);
    }
    
    int minDistance(string str1, string str2) {
           int n = str1.size();
       int m = str2.size();
       return n+m - 2*(longestCommonSubseq(n,m,str1,str2));
    }
};
