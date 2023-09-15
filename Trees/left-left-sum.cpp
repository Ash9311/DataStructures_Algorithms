class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root==NULL) return 0;
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)  sum+=root->left->val; //from parent node check if its child is a left leaf
        
        sum += sumOfLeftLeaves(root->left); //we must compute for right subtree left leaf node too. dont frget
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
