
make 2 for loops, one with product starting from left and other with right, if the count of continous negative number is
even we get in first for loop else the other.

so by using 2 for loops starting from left,right we get results in different orders
    
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int res = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            prod = prod * nums[i];
            res = max(res,prod);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod = prod * nums[i];
            res = max(res,prod);
            if(prod==0){
                prod=1;
            }
            
             
        }
         return res;
    }
      
};
