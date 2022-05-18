class Solution {
    public int uniquePaths(int m, int n) {
        int[][] map = new int[m][n];
        int i=0,j=0;
        for( i=0;i<m;i++){
            map[i][0]=1;
        }
        
        for(j=0;j<n;j++){
            map[0][j]=1;
        }
        
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                map[i][j] = map[i-1][j]+map[i][j-1];
            }
        }
        return map[m-1][n-1];
    }
}




//cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
