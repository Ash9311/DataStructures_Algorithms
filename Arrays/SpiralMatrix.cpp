//https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int i,k=0,l=0;
        int row = matrix.size();
        int col = matrix[0].size();
        
        while(k<=row-1 and l<=col-1){
        for(int i=l;i<col;i++){
            res.push_back(matrix[k][i]);
        }
            k++;
            
            for(int i=k;i<row;i++){
                res.push_back(matrix[i][col-1]);
            }
            col--;
            
            if(k<row){
                for(int i=col-1;i>=l;i--){
                    res.push_back(matrix[row-1][i]);
                }
                row--;
                
            }
            
            if(l<col){
                for(int i=row-1;i>=k;i--){
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
            
        }
        return res;
    }
};
