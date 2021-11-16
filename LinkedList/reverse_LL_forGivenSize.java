//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution
{
    public static Node reverse(Node node, int k)
    {
        //Your code here
        Node curr = node;
        Node prev = null;
        Node next = null;
        int i=0;
        while(curr!=null && i<k){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        if(next!=null){
            node.next=reverse(next,k);
        }
        return prev;
        
    }
}
