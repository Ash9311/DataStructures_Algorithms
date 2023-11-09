//https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1; //validate
        grid[0][0]=1; //similar to marking as visited
        queue<pair<int,int>> q;  //<row,col>
        q.push({0,0});
      
        while(q.size()){
            int size = q.size();
            while(size--){ //process all possible paths for current cell and then only move to next. shortest distance will b stored
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row==n-1 && col==n-1) return grid[row][col]; //destination reached
            int delRow[8]= {1,-1,0,0,1,1,-1,-1}; //explore all 8 possible neighbours
            int delCol[8]= {1,-1,1,-1,0,-1,0,1};
            for(int i=0;i<8;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<n && grid[nRow][nCol]==0){ //validate
                    grid[nRow][nCol] = 1+grid[row][col]; //since its 1 step away from current grid
                    q.push({nRow,nCol});
                }
            }
        }
        }
        return -1;
    }
};
