//https://leetcode.com/problems/number-of-islands/submissions/

class Solution {
    
    public int m;
    public int n;
    public int numIslands(char[][] grid) {
        n = grid.length;
        int count=0;
        m = grid[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                DFS(i,j,grid);
                count++;
                }
            }
        }
        return count;
    }
    
    public void DFS(int i,int j,char[][] grid){
        if(i<0 || j<0 || i>=n || j>=m ||grid[i][j]!='1'){
            return;
        }
        grid[i][j]='0';
        DFS(i+1,j,grid);
        DFS(i-1,j,grid);
        DFS(i,j+1,grid);
        DFS(i,j-1,grid);
    }
}
