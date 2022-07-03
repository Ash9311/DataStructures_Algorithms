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

class cmp{
    public:
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};
//add all the nodes in a Min Priority Queue, make a new ListNode and insert the values to it from Priority Queue
class Solution {
public:
 
    ListNode* mergeKLists(vector<ListNode*>& lists) { //in input section it looks like 2D vector but its 1D, since its a linked list
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;  //for min heap we need to add 2nd and 3rd parameters
       
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]); //only head will be stored, next nodes wont be
            }
        }
        
        while(pq.size()){ //we have the values in pq, creating a ListNode out of it
            ListNode *temp = pq.top();
            tail->next = temp;
            tail = temp;
            pq.pop();
            if(temp->next!=NULL){ //since only head are being stored ,we need to check for next nodes
                pq.push(temp->next); //since its a min pq, order will get arranged
            }
        }
        return dummy->next; //since first node of dummy is -1
    }
};
