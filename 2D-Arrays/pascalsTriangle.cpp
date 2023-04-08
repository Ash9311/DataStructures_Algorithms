https://leetcode.com/problems/pascals-triangle/description/

//for each row first declare a vector of size o tht row with value filled with 1. then iterate that row and fill values depending on the previous 
//row if there and push that row vector to the resultant 2d vector.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1); //first declare a vector of size o tht row with value filled with 1
            for(int j=1;j<i;j++){ 
                row[j]=res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(row);
        }
        return res;
    }
};
