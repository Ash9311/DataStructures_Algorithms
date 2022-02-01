//https://leetcode.com/problems/n-queens/submissions/
class Solution {
    
    public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        int duprow=row;
        int dupcol=col;
        
        while(row>=0 and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        
        row=duprow;
        col = dupcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        
        col=dupcol;
        while(row<n and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
            }
        return true;
    }
    
    public:
    void solve(int n,vector<string> &board,vector<vector<string>> &res,int col){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(n,board,res,col+1);
                board[row][col]='.';
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
        solve(n,board,res,0);
        return res;
    }
};
