//https://leetcode.com/problems/range-sum-query-2d-immutable/description/
//first create a prefix matrix.

[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
    
3 3 4 8 10 
8 14 18 24 27 
9 17 21 28 36 
13 22 26 34 49 
14 23 30 38 58 
    
class NumMatrix {
public:
int row,col;
vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        sums = vector<vector<int>>(row+1,vector<int>(col+1));

        for(int i=1;i<=row;i++){ //starting from i=1,j=1 bcoz or else v must add separate condition for 0,0
            for(int j=1;j<=col;j++){
                sums[i][j] = matrix[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
            }
        }
    }


    // basically when 2 coordinates are given. i.e r1,c1 and r2,c2. first find
//from (0,0) to r2,c2 and then subtract the unnecessary ones. and add the sum which got subtracted twice
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];
    }
};
