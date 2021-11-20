//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
/* The structure of linked list is the following
class Node
{
    int data;
    Node next;
    Node(int d) {
        data = d; 
        next = null;
    }
}
*/

class Solution
{
    //Function to remove duplicates from unsorted linked list.
    public Node removeDuplicates(Node head) 
    {
         // Your code here
         Node curr = head;
         HashSet<Integer> hs = new HashSet<>();
         
         while(curr.next!=null){
             hs.add(curr.data);
             if(hs.contains(curr.next.data)){
                 curr.next = curr.next.next;
             }
             else{
                 curr=curr.next;
             }
            
         }
         return head;
    }
}
