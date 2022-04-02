//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    
        void traverseTree(TreeNode *root,int d,map<int,vector<int>> &mp){
            if(root==NULL){
                return;
            }
            mp[d].push_back(root->val);
            traverseTree(root->left,d-1,mp);
            traverseTree(root->right,d+1,mp);
        }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        int d=0;
        traverseTree(root,d,mp);
        for(auto p:mp){
           res.push_back(p.second);
        }
        return res;
    }
};
