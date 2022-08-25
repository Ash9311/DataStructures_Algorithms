//cpp https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
//traverse recursively and check lvl==ans.size() condition to determine first node of new level, traverse right first.
class Solution
{
    public:
    
    void solve(Node *root,vector<int> &ans,int lvl){
    if(root==NULL){
        return;
    }
  
    //by this condition we get to know that we entered a new level
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right,ans,lvl+1); //traverse right first and increment lvl
    solve(root->left,ans,lvl+1);
    
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
   solve(root,ans,0);
   return ans;
    }
};   







//java
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ls = new ArrayList<Integer>();
        rightView(root,ls,0);
        return ls;
    }
    
    public void rightView(TreeNode curr,List<Integer> res, int depth){
        if(curr==null){
            return;
        }
        if(depth==res.size()){
            res.add(curr.val);
        }
        
        
        rightView(curr.right,res,depth+1);
         rightView(curr.left,res,depth+1);
        
    }
}
