//https://leetcode.com/problems/balanced-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int depth(TreeNode *root){
        if(root==NULL){
            return NULL;
        }
        return max(depth(root->left),depth(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(right-left)<=1 and isBalanced(root->left) and isBalanced(root->right);
    }
};
