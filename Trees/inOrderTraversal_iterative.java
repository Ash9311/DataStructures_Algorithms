/* A Binary Tree node 

class Node {
    int data;
    Node left, right;
   Node(int item)    {
        data = item;
        left = right = null;
    }
} */
class Solution
{
    // Return a list containing the inorder traversal of the given tree
    ArrayList<Integer> inOrder(Node root)
    {
        ArrayList<Integer> arl = new ArrayList<Integer>();
        Stack<Node> stack = new Stack<Node>();
        while(true){
            while(root!=null){

                stack.push(root);
                root = root.left;
            }
            
            if(stack.empty()){
                break;
            }
           
            root=stack.pop();
            arl.add(root.data);
            root = root.right;
        }
        return arl;
    }
    
    
}
