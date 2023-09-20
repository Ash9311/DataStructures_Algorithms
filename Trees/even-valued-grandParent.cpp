//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        if(root->val%2==0){ //if current node is even check for its grand childrens
            if(root->left){
                  if(root->left->left){
                     sum+=root->left->left->val;
                  }
                   if(root->left->right){
                     sum+=root->left->right->val;
            
            }
            }
          
          if(root->right){
                    if(root->right->left){
                sum+=root->right->left->val;
            }
             if(root->right->right){
                sum+=root->right->right->val;
            }
          }
       
        }
        int left = sumEvenGrandparent(root->left); //explore other nodes
        int right = sumEvenGrandparent(root->right);
        return sum+left+right; //remember to add current node sum too along with its childrens
    }
};
