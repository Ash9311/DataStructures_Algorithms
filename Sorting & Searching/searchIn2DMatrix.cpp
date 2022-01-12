class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=matrix[0].size()-1;
        int i = 0;
        
        while(j>=0 and i<matrix.size()){
            if(matrix[i][j]>target){
                j--;
            }
              else if(matrix[i][j]<target){
                i++;
            }
            else{
                return true;
            }
            
        }
        return false;
    }
};
