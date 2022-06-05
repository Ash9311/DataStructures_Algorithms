//https://leetcode.com/problems/product-of-array-except-self/submissions/

initialize two variable left,right with 1, make a vector res with values set to 1

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left=1,right=1;
        vector<int> res(nums.size());
        //nums[1,2,3,4]
        for(int i=0;i<nums.size();i++){
            res[i]=1;
        }
        //res=[1,1,1,1]
        for(int i=0;i<nums.size();i++){
            res[i]=res[i]*left;
            left = left*nums[i];
        }
        //res=[1,1,2,6]
        
        for(int j=nums.size()-1;j>=0;j--){
            res[j]=res[j]*right;//6*1..2*4..1*12..1*24
            right =right*nums[j];//1*4..4*3..12*2..24*1
            cout<<right<<" ";
        }
        //res=[,8,6]
        return res;
    }
};
