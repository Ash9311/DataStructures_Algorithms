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
        bool left = isBalanced(root->left); //recursive approach to check all nodes(since condition must hold for all nodes)
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


#optimized

class Solution{
    public:
    //make a use of pair of bool,int. bool to check if the tree is balanced and int to track the height recursively.
    //once we get everything apply the parameters to the eqn and get the ans
    pair<bool,int> isBalancedFast(Node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool leftans = left.first; //is balanced check
        bool rightans = right.first;
        
        bool diff = abs(left.second - right.second) <=1; //condition check
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1; //calculating height on the go, instead of doing separately
        
        if(leftans and rightans and diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
        
    }
    
    bool isBalanced(Node *root)
    {
        pair<bool,int> result = isBalancedFast(root);
        return result.first;
        
    }
};
