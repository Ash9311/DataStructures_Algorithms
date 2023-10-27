//https://leetcode.com/problems/ones-and-zeroes/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));//3d dp since there r 3 varying parameters
        return solve(strs,m,n,l-1,dp);
    }

    int solve(vector<string>&strs,int m,int n,int l,vector<vector<vector<int>>> &dp){
         if(l<0){
            return 0;
        }
        if(dp[l][m][n]!=-1) return dp[l][m][n];
        int zero=0,one =0;
        for(int i=0;i<strs[l].size();i++){ //compute counts of current index
            if(strs[l][i]=='0') zero++;
            else one++;
        }
       
        int notPick = solve(strs,m,n,l-1,dp);
        int pick = INT_MIN; //so that it doesnt get considered if below condition isnt fulfiled
        if(m-zero>=0 && n-one>=0) pick = 1+solve(strs,m-zero,n-one,l-1,dp); //if condition fulfills +1 count 
        return dp[l][m][n]=max(pick,notPick);
    }
};
