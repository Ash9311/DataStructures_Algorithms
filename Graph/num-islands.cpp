//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){ //iterate through the grid. if its a land then 
            for(int j=0;j<m;j++){ //apply DFS. increment count. 
                if(grid[i][j]=='1'){
                    DFS(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }

    void DFS(int i,int j,int n,int m,vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0'; //so that we dont come here again, and then explore all directions
        DFS(i+1,j,n,m,grid);
        DFS(i,j+1,n,m,grid);
        DFS(i-1,j,n,m,grid);
        DFS(i,j-1,n,m,grid);
    }
};
