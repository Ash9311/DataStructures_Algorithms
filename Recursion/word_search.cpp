//https://leetcode.com/problems/word-search/submissions/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(adjacentsearch(board,word,i,j,0)){
            return true;
            }
            }
        
        }
        return false;
    }
    
    bool adjacentsearch(vector<vector<char>> &board,string word,int i,int j ,int index){
        if(index==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1){
            return false;
        }
        if(board[i][j]!=word[index]){
            return false;
        }
        board[i][j]='*';
        bool furtherSearch= adjacentsearch(board,word,i+1,j,index+1)||adjacentsearch(board,word,i-1,j,index+1)
            ||adjacentsearch(board,word,i,j-1,index+1)||adjacentsearch(board,word,i,j+1,index+1);
        
        board[i][j]=word[index];
        return furtherSearch;
    }
};
