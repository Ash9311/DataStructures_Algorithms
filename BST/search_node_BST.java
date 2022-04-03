//https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/#


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
