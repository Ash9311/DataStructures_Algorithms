//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//we are writing for dest to src. so that top down approach becomes easier.
//declare a dp vector to memoize and start fromn m-1,n-1 . write base condition,boundary condition
//recursively explore all possibilities on each index and store and return the sum.
int mod = (int)(1e9 +7);
int f(int row,int col,vector<vector<int>> &dp,vector< vector< int> > &mat){
    if(row==0 && col==0){//top down appraoch base condition
        return 1;
    }
    if(row<0 or col<0){//out of boundary
        return 0;
    }
    if(row>=0 && col>=0 && mat[row][col]==-1){ //when valid cell is blocked
        return 0;
    }
    if(dp[row][col]!=-1){  //check for overlapping sub problem
        return dp[row][col];
    }
    int left = f(row,col-1,dp,mat);//recursively call for up,left
    int up = f(row-1,col,dp,mat);
    return dp[row][col] = (left + up)%mod; //memoize
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,dp,mat)%mod;
}

//tabulation
     int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1){ //when valid cell is blocked
                dp[i][j] = 0;
            }
            else if(i==0 and j==0){
                dp[i][j] = 1;
            }
            else{
                int up=0,left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = (up + left)%mod;
            }
        }
    }
    return dp[n-1][m-1]%mod;
}
