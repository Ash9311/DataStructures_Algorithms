//https://leetcode.com/problems/binary-tree-paths/
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
//use recursive approach to traverse through the tree and add the val of node to the temp string. push it to the resultant vector
class Solution {
public:
    
    void solve(TreeNode* root,string temp,vector<string> &result){
        if(root->left==NULL and root->right==NULL){
            temp+=to_string(root->val); //add the last val
            result.push_back(temp);
            return; //after returning temp will be cleared as we are passing it by value
        }
        temp+=to_string(root->val)+"->";
        
        if(root->left){
        solve(root->left,temp,result);
        }
        
        if(root->right){
        solve(root->right,temp,result);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
         if(!root){
            return result;
        }
         string temp = "";
        solve(root,temp,result);
        return result;
    }
};
