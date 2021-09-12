/* A binary tree node class
class Node
{
	int data;
	Node left,right;
	
	Node(int d)
	{
		data = d;
		left = right = null;		
	}
} */

class Tree
{
    
    //Function to check whether a binary tree is balanced or not.
    boolean isBalanced(Node root)
    {
	// Your code here
	if(root==null){
	    return true;
	}
	int left = height(root.left);
	int right = height(root.right);
	return Math.abs(left-right)<2 && isBalanced(root.left) && isBalanced(root.right); //said to be balanced if difference if right and left subtree is not greater than 1
    }
    
    int height(Node root){
        if(root==null){
            return 0;
        }
        return Math.max(height(root.left),height(root.right))+1;
    }
}

