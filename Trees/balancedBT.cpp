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

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node *root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left)+1;
        int right = height(root->right)+1;
        
        return max(left,right);
    }
    
    bool isBalanced(Node *root)
    {
        
        if(root==NULL){
            return true;
        }
        bool left = isBalanced(root->left); //recursive approach to check all nodes
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right))<=1;
        if(left and right and diff){
            return true;
        }
        return false;
    }
};


//#2
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
