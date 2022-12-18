//https://leetcode.com/problems/shortest-common-supersequence/description/

//prepare subsequence table and then starting from the last index backtrack.
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //longest common subseq
        for(int j=0;j<m;j++) dp[0][j]=0;
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }
//-------------------------
//once you have LCS dp 2d array start from the last index and backtrack
        string ans ="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){//if its a match then go to the left diagonal of 2d array
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1]; //since we are ommitting 'i' add it to our ans
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }

    //add up the remaining string in either case
    while(i>0){
        ans+=str1[i-1];
        i--;
    }

    while(j>0){
        ans+=str2[j-1];
        j--;
    }

    //reverse the ans. since we started from the end backtracking
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
