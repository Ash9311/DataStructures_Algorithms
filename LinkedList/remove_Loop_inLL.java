//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

/*
class Node
{
    int data;
    Node next;
}
*/

class Solution
{
    // public static Node detectLoop(Node head){
        
    //     Node hare = head;
    //     Node turtle = head;
        
    //     while(hare.next!=null  && hare!=null){
    //         turtle = turtle.next;
    //         hare = hare.next.next;
    //         if(hare==turtle){
    //             return hare;
    //         }
    //     }
    //     return hare;
    // }
    //Function to remove a loop in the linked list.
    public static void removeLoop(Node head){
        
    //   Node meet = detectLoop(head);
      
    //   Node prevOfMeet = meet;
    //   int flag=0;
    //   Node start = head;
    //   //System.out.println(start.data+" "+meet.data+" "+prevOfMeet.data);
    //   while(meet!=start){
           
    //       meet = meet.next;
    //       start = start.next;
    //       if(flag==1){
              
    //           prevOfMeet = prevOfMeet.next;
    //       }
    //       flag=1;
    //   }
    //   if(flag==0){
    //       start = start.next;
    //       while(start.next!=meet){
    //           start=start.next;
    //       }
    //       start.next=null;
    //   }
    //   else{
     
    //   prevOfMeet.next = null;
    //   }
       HashSet<Node> hs = new HashSet<>();
       Node curr = head;
       while(curr!=null){
           hs.add(curr);
           if(curr.next!=null && hs.contains(curr.next)){
               curr.next=null;
               break;
               
           }
           curr = curr.next;
       }
    }
}
