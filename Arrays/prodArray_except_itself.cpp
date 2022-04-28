//https://leetcode.com/problems/product-of-array-except-self/submissions/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left=1,right=1;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            res.push_back(1);
        }
        
        for(int i=0;i<nums.size();i++){
            res[i]=res[i]*left;
            left = left*nums[i];
        }
        
        for(int j=nums.size()-1;j>=0;j--){
            res[j]=res[j]*right;
            right =right*nums[j];
        }
        return res;
    }
};
