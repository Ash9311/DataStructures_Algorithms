//https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/#
//cpp
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data<x){
        searchInBST(root->right,x);
    }
    else if(root->data>x){
        searchInBST(root->left,x);
    }
}


//java
class BST {
    // Function to search a node in BST.
    boolean search(Node root, int x) {
        // Your code here
        if(root==null){
            return false;
        }
        else if(x<root.data){
            return search(root.left,x);
        }
        else if(x>root.data){
            return search(root.right,x);
            
        }
        
       return true;
       
     
    }
}
