//https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
int ans=0;
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return ans;
    }

    void solve(TreeNode* root,int sum){
        if(!root) return;
        sum= sum*10+root->val;
        if(root->left==NULL && root->right==NULL){  // If it's a leaf node, return the sum
            ans+=sum; //add subtree sum to ans
            return;
        }
        solve(root->left,sum); // Otherwise, recursively calculate sums in left and right subtrees
        solve(root->right,sum);
    }

//     int solve(TreeNode* root, int sum) {   method-2
//     if (!root) return 0;

//     // Calculate the current sum along the path
//     sum = sum * 10 + root->val;

//     // If it's a leaf node, return the sum
//     if (!root->left && !root->right) {
//         return sum;
//     }

//     // Otherwise, recursively calculate sums in left and right subtrees
//     int leftSum = solve(root->left, sum);
//     int rightSum = solve(root->right, sum);

//     // Return the sum of sums from left and right subtrees
//     return leftSum + rightSum;
// }
};
