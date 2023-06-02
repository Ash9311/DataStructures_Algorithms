//https://leetcode.com/problems/merge-two-sorted-lists/submissions/
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

//res->next will recursively add on nodes in a sorted manner

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode *res;
        if(list1->val < list2->val){
            res = list1;
            res->next = mergeTwoLists(list1->next,list2);
        }
        else{
            res = list2;
            res->next = mergeTwoLists(list1,list2->next);
        }
        return res;
    }
};


---------------
    class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode *res=new ListNode();
       ListNode *curr = res;
       ListNode *curr1=list1;
       ListNode *curr2=list2;

        while(curr1!=NULL && curr2!=NULL){ //2 pointer sort approach
            if(curr1->val<curr2->val){
                curr->next = curr1; 
                curr1 = curr1->next; 
            }
            else{
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next; //move curr forward
        }
           

        while(curr1!=NULL){ //add either remaining one
            curr->next = curr1;
                curr1 = curr1->next;
                curr = curr->next;  //move curr forward
        }
                while(curr2!=NULL){
            curr->next = curr2;
                curr2 = curr2->next;
                curr = curr->next;
        }
        return res->next;
    }
};
