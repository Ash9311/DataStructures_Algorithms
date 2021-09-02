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
class Solution
{
    //Function to return the level order traversal of a tree.
    static ArrayList <Integer> levelOrder(Node node) 
    {
        // Your code here
        ArrayList<Integer> arr = new ArrayList<Integer>();
        if(node==null){
            return arr;
        }
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        while(!(q.isEmpty())){
            Node temp = q.poll();
            arr.add(temp.data);
            
            if(temp.left!=null){
                q.add(temp.left);
            }
            if(temp.right!=null){
                q.add(temp.right);
            }
        }
        return arr;
    }
}
