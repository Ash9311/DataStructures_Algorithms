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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(nodes,root);
        return nodes;
    }
    
    public: void preorder(vector<int>& nodes,TreeNode* root){
        if(!root){
            return;
        }
        nodes.push_back(root->val);
        preorder(nodes,root->left);
        preorder(nodes,root->right);
    }
    
};
