//https://leetcode.com/problems/rotting-oranges/description/
//first make a queue of pair of pair and traverse through the grid. make a note of rotten oranges at time 0. push it to the queue. and process
//each element of the queue check for its neighbours too . and then validate and return the time taken.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // {{r,c},t}
        queue<pair<pair<int,int>,int>> q;
        int vis[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); //store index of rotten oranges here
                    vis[i][j]=2;
                }
                else{
                    vis[i][j] = 0;
                }               
            }
        }

        int timer = 0;
        int drow[] = {-1,0,+1,0}; //delta to know neighbouring
        int dcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first; //get the row,col,time for rotten oranges
            int c = q.front().first.second;
            int t = q.front().second;
            timer = max(timer,t);
            q.pop();

            for(int i=0;i<4;i++){
                int neighRow = r + drow[i]; //gets indexes of neighbouring oranges of rotten orange
                int neighCol = c + dcol[i];
                if(neighRow>=0 && neighRow<row && neighCol<col && neighCol>=0 && vis[neighRow][neighCol]==0 && grid[neighRow][neighCol]==1){ //boundary check ,visit check,rotten check
                    q.push({{neighRow,neighCol},timer+1});
                    vis[neighRow][neighCol] = 2;
                }
            }
        }
        for(int i=0;i<row;i++){ // check if any is not rotten, since we need to rotten all
            for(int j=0;j<col;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return timer;

    }
};
