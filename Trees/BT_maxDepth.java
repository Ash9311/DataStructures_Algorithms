//https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
class Solution {
    
    private:
    int solve(TreeNode* root,int depth,int maxDepth){
        if(root==NULL){
            return depth;
        }
        int left =solve(root->left,depth+1,maxDepth);
        int right =solve(root->right,depth+1,maxDepth);
        
        return max(left,right);
        
    }
    
public:
    int maxDepth(TreeNode* root) {
        int maxDepth=0;
        int depth=0;
        return solve(root,depth,maxDepth);
    }
};



/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        int left_depth = maxDepth(root.left)+1;
        int right_depth = maxDepth(root.right)+1;
        return left_depth>right_depth?left_depth:right_depth;
    }
}
