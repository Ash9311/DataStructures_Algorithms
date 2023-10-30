//https://leetcode.com/problems/unique-binary-search-trees-ii/
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

private:
 vector<TreeNode*> solve(int start,int end){
     if(start>end) return {nullptr};
     vector<TreeNode*> res;
     for(int i=start;i<=end;i++){ // For every number ( i ) in the range from start to end, consider ( i ) as the root of the tree.
         vector<TreeNode*> left = solve(start,i-1); //recursively call functions to generate all possible sub trees
         vector<TreeNode*> right = solve(i+1,end);

         for(TreeNode* l: left){ //combine subtrees
             for(TreeNode* r: right){
                 TreeNode* curr = new TreeNode(i);
                 curr->left = l;
                 curr->right = r;
                 res.push_back(curr);
             }
         }
     }
     return res;
 }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector
        return n?solve(1,n): vector<TreeNode*>();
    }
};
