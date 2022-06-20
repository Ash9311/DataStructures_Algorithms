//https://leetcode.com/problems/set-matrix-zeroes/

//create a duplicate vector and if there are zeroes there then perform the operation on original vector

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int row = matrix.size();
        int col = matrix[0].size();
        int k=0;
        vector<int> temp;
        vector<vector<int>> dupli;
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                temp.push_back(matrix[i][j]);
            }
             dupli.push_back(temp);
             temp.clear();
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dupli[i][j]==0){
                    for(k=0;k<col;k++){
                        matrix[i][k]=0;
                    }
                    for(k=0;k<row;k++){
                        matrix[k][j]=0;
                    }
                }
            }
        }
    
    }
};
