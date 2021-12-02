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
