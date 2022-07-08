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
                board[row][col]='.'; //backtrack and try for different combinations
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

------------------------------------------------------
    
    //https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1/#
    
    //maintain  a vector board whose value is initialized to n zeroes which represents each row of chess board
    //iterate through each column see if its safe to place queen, if safe mark as visisted and then backtrack
    
    class Solution{
public:
    
    bool isSafe(vector<vector<int>> board,int x,int y,int n){
        for(int i=0;i<x;i++){
            if(board[i][y]==1){ //vertical up check
                return false;
            }
        }
        
        int row=x,col=y;
        while(row>=0 and col>=0){ //upper left diagonal check
            if(board[row][col]==1){
                return false;
            }
            row--;
            col--;
            
        }
        
        row=x,col=y;
        while(row>=0 and col<n){ //upper right diagonal check
            if(board[row][col]==1){
                return false;
            }
            row--;
            col++;
        }
        return true;
        
    }

    void solve(int x,int n,vector<vector<int>> &board,vector<vector<int>> &result){
        if(x==n){
            vector<int> v;  //since we need array of column indexes
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==1){
                        v.push_back(j+1);
                    }
                }
            }
            result.push_back(v);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(board,x,col,n)){
                board[x][col]=1; //marks as visited
                solve(x+1,n,board,result);
                board[x][col]=0; //omit the visited sign so that it doesnt interfere with new path which we explore
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(0,n,board,result);
        sort(result.begin(),result.end());
        return result;
        
    }
};
