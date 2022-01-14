//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
//     public int BinaryToDecimal(int bn){
//         int decimal=0;
//         int p=0;
//         while(bn>0){
//             int temp = bn%10;
//             decimal += temp * Math.pow(2,p);
//             bn=bn/10;
//             p++;
                
//         }
//         return decimal;
//     }

    public int getDecimalValue(ListNode head) {
        String s ="";
        int n=0;
        while(head!=null){
            s+=Integer.toString(head.val);
            head = head.next;
        }
       
        return Integer.parseInt(s,2);
    }
}
