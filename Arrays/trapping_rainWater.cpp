//https://leetcode.com/problems/trapping-rain-water/submissions/



class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left;
        vector<int> right;
        int maxLeft=-1;
        int maxRight=-1;
        int h[n];
        int result=0;
        
       for(int i=0;i<n;i++){
           maxLeft = max(maxLeft,height[i]);
           left.push_back(maxLeft);
       }
        
         for(int i=n-1;i>=0;i--){
           maxRight = max(maxRight,height[i]);
           right.push_back(maxRight);
       }
        reverse(right.begin(),right.end());
        
        for(int i=0;i<n;i++){
            result += min(left[i],right[i])-height[i];
            
        }
        return result;
    }
};


make an array left where each index is containing max value of current index height and the left most, similarly do it for right,
 after that take the minimum of left and right and subtract it with current height, therefore you will be getting water that can be
 stored in each block.


// using arrays
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        left[0]=height[0];
        
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        
        right[n-1]=height[n-1];
        
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            res+=min(left[i],right[i])-height[i];
        }
        
        return res;
    }
};
