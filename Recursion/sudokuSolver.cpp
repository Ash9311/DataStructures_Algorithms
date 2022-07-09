//https://leetcode.com/problems/sudoku-solver/submissions/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        
                        if(solve(board)==true){
                            return true;
                        }else{
                            board[i][j]='.';
                        }  
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>> &board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c){
                return false;
            }
            if(board[row][i]==c){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                return false;
            }
        }
        return true;
    }
};


------------------------------
    //https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1#
    
    //traverse through all the elements of 2d sudoku check if there is any empty (i.e 0) element. and then
    //use a recursive approach and check for all 9 combination until you find a valid one.
    class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(char c=1;c<=9;c++){
                        if(isValid(grid,i,j,c)){
                            grid[i][j] = c;
                            if(SolveSudoku(grid)==true){ //if all possibilities are set
                                return true;
                            }
                            else{
                                grid[i][j]=0; //backtrack and explore other combination
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int grid[N][N],int row,int col,char c){
        for(int i=0;i<9;i++){
            if(grid[i][col]==c){ //check all the elements in the current column
                return false;
            }
            if(grid[row][i]==c){ //check all the elements in the current row
                return false;
            }
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] ==c){ //check for sub grid..using this logic we will be getting all 9 elements if subgrid
                return false;
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0; j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
