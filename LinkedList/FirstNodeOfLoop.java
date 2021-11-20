/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    
    public static boolean isCycle(ListNode head){
        ListNode hare = head;
        ListNode turtle = head;
        while(hare!=null && hare.next!=null){
            turtle = turtle.next;
            hare = hare.next.next;
            if(hare==turtle){
                return true;
            }
            
        }
        return false;
    }
    
    
    public static ListNode Cyclemeet(ListNode head){
        ListNode hare = head;
        ListNode turtle = head;
        while(hare!=null && hare.next!=null){
            turtle = turtle.next;
            hare = hare.next.next;
            if(hare==turtle){
                return hare;
            }
            
        }
        return null;
    }
    
    public ListNode detectCycle(ListNode head) {
       if((head==null || head.next==null) || !(isCycle(head))){
           return null;
       }
    
        
        ListNode meet = Cyclemeet(head);
        ListNode curr = head;
        while(meet!=curr){
            meet = meet.next;
            curr = curr.next;
        }
        return meet;
    }
}
