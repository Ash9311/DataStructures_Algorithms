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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> sub;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node==NULL){  //we get to know that current level is done
            v.push_back(sub);
            sub.clear();
                   
            if(q.size()){
                q.push(NULL);
                    }
                }
            
            else{
                sub.push_back(node->val);
                if(node->left){
                 q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }   
        }
        return v;
    }
};
