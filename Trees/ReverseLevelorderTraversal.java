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

class Tree
{
    public ArrayList<Integer> reverseLevelOrder(Node node) 
    {
        // code here
        ArrayList<Integer> arr = new ArrayList<Integer>();
        if(node==null){
            return arr;
        }
        Queue<Node> q = new LinkedList<Node>();
        q.add(node);
        while(!(q.isEmpty())){
            Node temp = q.poll();
            arr.add(temp.data);
            if(temp.right!=null){
                q.add(temp.right); //going for right first so that we get the list in reversed format
            }
            if(temp.left!=null){
                q.add(temp.left);
            }
        }
        Collections.reverse(arr);
        return arr;
    }
}      
