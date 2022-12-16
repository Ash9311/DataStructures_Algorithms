//Minimum Insertion Steps to Make a String Palindrome =  length of string - Longest palindromic subsequence
class Solution {
public:
//since we need ti find longest palindromic subsequence. reverse the given string and then find the
//longest common subsequence from those 2 strings
//start with last indexes of both strings.recursively explore all indexes. if string index is a match move both indexes 1 step back.
//if string isnt a match then split it into two cases. where index of 1 string is not moved and other is moved. and return the max of those
// without memoization TC-O(2^n * 2^m)
//TC-O(n*m) SC-O(n*m)+O(n+m)
  
//   int solve(int i,int j,string s1,string s2,vector<vector<int>> &dp){    //recursion TLE
//         if(i<0 || j<0){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s1[i]==s2[j]){
//             return 1+solve(i-1,j-1,s1,s2,dp);
//         }
//         return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp)); //if not a match then split to two cases and return the max
//     }
  

//     int longestPalindromeSubseq(string s1) {
//         int n = s1.size();
//         string s2 = string(s1.rbegin(), s1.rend());
//          vector<vector<int>> dp(n,vector<int>(n,-1));
//        return solve(n-1,n-1,s1,s2,dp);
//     }
  
  //TABULATION
    int solve(string s1) {
        int n = s1.size();
        string s2 = string(s1.rbegin(), s1.rend());
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++){ 
            dp[0][i]=0;
            dp[i][0]=0;
        }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
              }
              else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
      }

       return dp[n][n];
    }

     int minInsertions(string s) {
         int n = s.size();
       int LongestPalindromicSubseq= solve(s);
       return n-LongestPalindromicSubseq;
    }
};
