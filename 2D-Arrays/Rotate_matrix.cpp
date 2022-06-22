//https://leetcode.com/problems/rotate-image/

reverse the matrix and swap corresponding indexes, we will obtain 90 degree rotated matrix;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){  //j=i+1 is bcoz of avoiding swapping same elements (ex-a[0][0],a[0][0]), j=i will also lead to correct ans
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
    }
};
