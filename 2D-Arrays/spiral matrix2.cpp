//https://leetcode.com/problems/spiral-matrix-ii/description/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mt(n,vector<int>(n,0));
        int top = 0;
        int left = 0;
        int bottom = n-1;
        int right = n-1;
        int k=1;
        while(top<=bottom && left<=right){
         
            for(int i=left;i<=right;i++){ //rightwards
                mt[top][i]=k;
                k++;
            }
            top++;
              if(bottom>=top){
             for(int i=top;i<=bottom;i++){ //downwards
                mt[i][right]=k;
                k++;
            }
              }
            right--;
            if(bottom>=top){ //need this check for last iteration, or else it goes out of inner spiral
             for(int i=right;i>=left;i--){ //leftwards
                mt[bottom][i]=k;
                k++;
            }
            }

            bottom--;
            if(left<=right){
              for(int i=bottom;i>=top;i--){ //upwards
                mt[i][left]=k;
                 cout<<left<<endl;
                k++;
            }
            left++;
        }
        }
        return mt;
    }
};
