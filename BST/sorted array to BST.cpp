//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
//if only 1 node then thats the root. find middle of the sorted vector and recursively place smaller ones on left and larger ones on right.

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       if(nums.size()==0){
           return NULL;
       }
        if(nums.size()==1){
           return new TreeNode(nums[0]);
       }
         int mid = (nums.size())/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> leftInt(nums.begin(),nums.begin()+mid); //divide first half and second half 
        vector<int> rightInt(nums.begin()+mid+1,nums.end());
        root->left = sortedArrayToBST(leftInt);
        root->right = sortedArrayToBST(rightInt);
        return root;
    }

    
};
