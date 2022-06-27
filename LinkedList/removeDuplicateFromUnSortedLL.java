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

//maintain a hashset and check for duplicates

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



//cpp
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        Node *curr = head;
        unordered_set<int> hs;
        
        while(curr->next!=NULL){
            hs.insert(curr->data);
            if(hs.find(curr->next->data)!=hs.end()){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
