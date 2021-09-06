//User function Template for Java

/* A Binary Tree node 

class Node {
    int data;
    Node left, right;
   Node(int item)    {
        data = item;
        left = right = null;
    }
} */
class Tree
{
    // Return a list containing the inorder traversal of the given tree
    ArrayList<Integer> preOrder(Node root)
    {
         ArrayList<Integer> arl = new ArrayList<Integer>();
        Stack<Node> stack = new Stack<Node>();
        while(true){
            while(root!=null){
                arl.add(root.data);
                stack.push(root);
                root = root.left;
            }
            
            if(stack.empty()){
                break;
            }
            root=stack.pop();
            root = root.right;
        }
        return arl;
    }
    
    
}
