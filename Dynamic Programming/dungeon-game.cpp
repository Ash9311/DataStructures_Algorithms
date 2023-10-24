//https://leetcode.com/problems/dungeon-game/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,dungeon,dp);
    }

    int solve(int i,int j, int n,int m,vector<vector<int>> dungeon, vector<vector<int>>&dp){
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1) return dungeon[i][j]>0?1:(-1*dungeon[i][j]+1); //ex if last index is having -5 then v need +6 for minimum
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i,j+1,n,m,dungeon,dp);

        int down = solve(i+1,j,n,m,dungeon,dp);
        int res = min(right,down) - dungeon[i][j];
        return dp[i][j]=res>0?res:1;
    }
};
