class Solution {

    int height(Node root){
      
        if(root==null){
            return 0;
        }
       
        return 1+ Math.max(height(root.left),height(root.right));
    }
    
    int diameter(Node root) {
        // Your code here
       if(root==null){
           return 0;
       }
       
       int leftSubtree = height(root.left);
       int rightSubtree = height(root.right);
       
       int leftDiameter = diameter(root.left);
       int rightDiameter = diameter(root.right);
       
       return Math.max(leftSubtree+rightSubtree+1,Math.max(leftDiameter,rightDiameter));
       //find max diameter for tree with main root and without
       
        
    }
}


// class Solution {

//     int height(Node root){
      
//         if(root==null){
//             return 0;
//         }
       
//         return 1+ Math.max(height(root.left),height(root.right));
//     }
    
//     int diameter(Node root) {
//         // Your code here
//        if(root==null){
//            return 0;
//        }
       
//         int rootMain = (height(root.left) + height(root.right))+1;
        
//         int leftSide = diameter(root.left);
//         int rightSide = diameter(root.right);
        
        
//         return Math.max(rootMain,Math.max(leftSide,rightSide));
//     }
// }


// class Solution {
//     // Function to return the diameter of a Binary Tree.
//     int res=0;
//     int height(Node root){
//         // if(data==null){
//         //     return 0;
//         // }
//         // return 1+Math.max(height(root.left),height(root.right));
//         if(root==null){
//             return 0;
//         }
//         int lh = height(root.left);
//         int rh = height(root.right);
//         res = Math.max(res,lh+rh+1);
        
//         return 1+ Math.max(lh,rh);
//     }
    
//     int diameter(Node root) {
//         // Your code here
       
//         height(root);
//         return res;
//     }
// }



// class Solution {
// public:
// int maxx=0;
//     int maxDepth(TreeNode* root){
//         if(root==NULL){
//             return 0;
//         }
//         int left  = maxDepth(root->left);
//         int right = maxDepth(root->right);
//          maxx = max(left+right,maxx);
//         return max(left,right)+1;
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         maxDepth(root);
//         return maxx;
//     }
// };

