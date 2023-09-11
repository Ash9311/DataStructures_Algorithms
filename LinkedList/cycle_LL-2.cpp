//https://leetcode.com/problems/linked-list-cycle-ii/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* turtle = head;
        ListNode* hare = head;
        ListNode* ptr = NULL;
        int flag = 0;
        while(hare && hare->next){
           
            turtle = turtle->next;
            hare = hare->next->next;
             if(turtle==hare){ //using turtle hare logic confirm if a cycle exists
                flag =1;
                break;
            }
        }
        if(flag==0) return ptr; //if not just return empty
        turtle = head;
        while(turtle!=hare){ //put turtle to starting and hare at point of intersection itself. move both 1 step at time. and the common place where they meet is the 
            turtle = turtle->next; //place where a cycle originates
            hare = hare->next;
        }
        return turtle;
    }
};
