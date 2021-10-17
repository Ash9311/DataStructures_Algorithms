/* https://leetcode.com/problems/clone-graph/
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
       Map<Integer ,Node> map = new HashMap<Integer,Node>(); 
        return createNode(node,map);
        
    }
    
    Node createNode(Node node, Map<Integer,Node>map){
        if(node==null){
            return null;
        }
        Node newNode = new Node(node.val);
        map.put(node.val,newNode);
        
        for(Node n: node.neighbors){
            if(map.containsKey(n.val)){
                newNode.neighbors.add(map.get(n.val));
            }
            else{
                newNode.neighbors.add(createNode(n,map));
            }
        }
        return newNode;
    }
    
}
