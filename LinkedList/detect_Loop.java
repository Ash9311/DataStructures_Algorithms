//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}

*/


class Solution {
    //Function to check if the linked list has a loop.
    public static boolean detectLoop(Node head){
        // Add code here
        Node turtle = head;
        Node hare = head;
        
        while(hare!=null && hare.next!=null){
            
            turtle = turtle.next;
            hare = hare.next.next;
            if(hare==turtle){
                return true;
            }
        }
        return false;
    }
}

//cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *turtle = head;
        ListNode *hare = head;
        
        while(hare!=NULL and hare->next!=NULL){
            turtle = turtle->next;
            hare = hare->next->next;
            
            if(hare==turtle){
                return true;
            }
        }
        return false;
        
    }
};
