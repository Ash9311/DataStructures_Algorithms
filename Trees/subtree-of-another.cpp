//https://leetcode.com/problems/subtree-of-another-tree/
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root==NULL) return false;
       if(root->val==subRoot->val){ //if root is same then check if their childrens are same
           if(isSame(root,subRoot)) return true;
       }
       int left = isSubtree(root->left,subRoot); //if not explore 
       int right = isSubtree(root->right,subRoot);
       return left||right; //either is true, we have our ans
    }

    bool isSame(TreeNode* root1,TreeNode* root2){
       // if(root1->val==root2->val) return true; this condition is not used bcz root must not have additional childrens compared to subtree
        if(root1==NULL && root2==NULL) return true; // if checked for NULL then it is assured that this subtree is perfectly same as the given subroot
        if(root1==NULL || root2==NULL) return false;
        return root1->val==root2->val && isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
    }
};
