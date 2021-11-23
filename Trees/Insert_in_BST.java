//https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1#

class Solution {
    // Function to insert a node in a BST.
    Node insert(Node root, int Key) {
        // your code here
        if(root==null){
            return new Node(Key);
        }
        
        if(root.data < Key){
            root.right = insert(root.right,Key);
        }
        
        else if(root.data > Key){
            root.left = insert(root.left,Key);
        }
        
        return root;
    }
}
