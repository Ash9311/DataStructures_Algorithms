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
      //  rightView(curr.left,res,depth+1);
        
    }
}
