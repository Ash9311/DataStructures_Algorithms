https://leetcode.com/problems/n-queens/submissions/
class Solution {
    
    public:
    void solve(int n,vector<string> &board,vector<vector<string>> &res,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int>&upperDiagonal,int col){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[n-1 + col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1 + col-row]=1;
                solve(n,board,res,leftRow,lowerDiagonal,upperDiagonal,col+1);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 + col-row]=0;
                
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0);
        vector<int> lowerDiagonal(2*n - 1,0);
        vector<int> upperDiagonal(2*n -1,0);
        
        solve(n,board,res,leftRow,lowerDiagonal,upperDiagonal,0);
        return res;
    }
};
