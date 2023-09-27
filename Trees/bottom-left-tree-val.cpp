//https://leetcode.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res = -1;
        while(!q.empty()){ //traverse level wise and make a note of first node of each level
            int n = q.size();
            vector<int> level;
            while(n--){
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                if(curr->left){
                q.push(curr->left);
                }
                if(curr->right){
                q.push(curr->right);
                }
                q.pop();
            }
                res = level[0]; //so that we get first node of that level. can b optimized tho
        }
        return res;
    }
};
