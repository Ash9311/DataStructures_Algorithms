/*
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
*/

class GfG
{
    //Function to remove duplicates from sorted linked list.
    Node removeDuplicates(Node head)
    {
        // if(head==null || head.next==null){
        //     return null;
        // }
	  // HashSet<Integer> hs = new HashSet<>();
	    Node curr = head;
	    while(curr.next!=null){
	   //   if(curr.next==null){
	   //         break;
	   //     }
	       // hs.add(curr.data);
	       ////System.out.println(curr.data);
	       // if(hs.contains(curr.next.data)){
	       //     curr = curr.next.next;
	           
	       // }
	       // else {
	            
	       
	        if(curr.data==curr.next.data){
	            curr.next = curr.next.next;
	        }
	        else{
	            curr=curr.next;
	        }
	       
	    }
	     
	    return head;
    }
}
