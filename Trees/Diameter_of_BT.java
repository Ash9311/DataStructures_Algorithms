class Solution {
public:
int maxx=0;
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);
         maxx = max(left+right,maxx);
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxx;
    }
};

//#2

class Solution {
  public:
  
     int height(struct Node* node){
        
        if(node==NULL){
            return 0;
        }
        int left = height(node->left)+1;
        int right = height(node->right)+1;
        
        return max(left,right);
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       if(root==NULL){
            return 0;
        }
        //there are 3 ways, it might be in left subtree,right subtree or both
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;
        int ans = max(op1,max(op2,op3));
        return ans;
    }
};

//optimized
lass Solution {
  public:
    
    pair<int,int> diameterFast(Node* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
         pair<int,int> right = diameterFast(root->right);
         //first will be having diameter and second will be having height
         int op1 = left.first;
         int op2 = right.first;
         int op3 = left.second + right.second + 1;
         
         pair<int,int> ans;
         ans.first = max(op1,max(op2,op3));
         ans.second = max(left.second,right.second) + 1;
         return ans;
    }
     
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
      return diameterFast(root).first;
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
       
//        int leftSubtree = height(root.left);
//        int rightSubtree = height(root.right);
       
//        int leftDiameter = diameter(root.left);
//        int rightDiameter = diameter(root.right);
       
//        return Math.max(leftSubtree+rightSubtree+1,Math.max(leftDiameter,rightDiameter));
//        //find max diameter for tree with main root and without
       
        
//     }
// }


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




