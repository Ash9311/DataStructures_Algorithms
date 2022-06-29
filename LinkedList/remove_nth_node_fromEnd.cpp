//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//traverse through the LL get the length and then, traverse one node before target and then skip the target.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        
        int length=0;
        while(curr!=NULL){
            length++;
            curr = curr->next;
        }
        
        if(length==n){
            return head->next;
        }
        
        int target = length-n;
        int i=1;
        
       for(curr = head; i < target; i++){ 
           curr = curr -> next; // iterate first len-n nodes
       }
	curr -> next = curr -> next -> next;
        
        return head;
    }
};
