//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

//prepare del array to track neighbours and perform dfs starting from starting pixel. and then do it for its neighbours.
//change the color on 'ans' vector
class Solution {
    
private:
    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>>& image,int iniColor,int newColor,int delRow[],int delCol[]){
        ans[row][col] = newColor; //color it with new color forst
        int n = image.size();
        int m = image[0].size();
       for(int i=0;i<4;i++){ //process the neighbours
           int nRow = row + delRow[i];
           int nCol = col + delCol[i];
           if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColor && ans[nRow][nCol]!=newColor){ //validate
               dfs(nRow,nCol,ans,image,iniColor,newColor,delRow,delCol);
           }
       }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,+1,0}; //to track neighbours since adj matrix isnt given
        int delCol[] = {0,+1,0,-1};
        
        dfs(sr,sc,ans,image,iniColor,newColor,delRow,delCol);
        return ans;
    }
};
