//Max height of a tree is n-1 and min is floor(log2n)
/* 
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
 */

class Solution {
    //Function to find the height of a binary tree.
    int height(Node node) 
    {
        if(node==null){
            return 0;
        }
        
       return 1 + Math.max(height(node.left),height(node.right));
    }
}

// class Solution {
//     int height(Node node) {
//         // code here 
//         if(node==null){
//             return 0;
//         }
//         int l_depth=height(node.left);
//         int r_depth=height(node.right);
        
//         if(l_depth>r_depth){
//             return l_depth+1;
//         }
//         else{
//             return r_depth+1;
//         }
//     }
// }

// class Solution {
//     int height(Node node) {
//         // code here 
//         if(node==null){
//             return 0;
//         }
//         int l_depth=1+height(node.left);
//         int r_depth=1+height(node.right);
        
//         if(l_depth>r_depth){
//             return l_depth;
//         }
//         else{
//             return r_depth;
//         }
//     }
// }
