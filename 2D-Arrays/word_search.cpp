
//https://leetcode.com/problems/word-search/

iterate through the 2d board of char and use a recursive approach to check out each and every possibilities

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(adjacentsearch(board,word,i,j,0)){
                   return true;
               }
           }
       }
        return false;
    }
    
    bool adjacentsearch(vector<vector<char>> &board,string word,int i,int j ,int index){
        
        if(i<0 or i>board.size()-1 or j<0 or j>board[0].size()-1){ //boundary conditions
            return false;
        }
        
        if(board[i][j]!=word[index]){ //validating char
            return false;
        }
        
        if(index==word.size()-1){ //if it reaches upto last char then it means a match
            return true;
        }
        
        board[i][j]='.';  //so that we know the streak, will be backtracked later
        
        bool furtherSearch = adjacentsearch(board,word,i+1,j,index+1) or adjacentsearch(board,word,i-1,j,index+1)
            or adjacentsearch(board,word,i,j+1,index+1) or adjacentsearch(board,word,i,j-1,index+1); //check for all 4 directions if char is matching
        
        board[i][j]=word[index]; // bactrack and make it as it was so that we can explore other streak of words.
        return furtherSearch;
       
    }
};
