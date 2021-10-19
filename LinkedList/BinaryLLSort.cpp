/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL or A->next==NULL){
        return A;
    }
    ListNode* count=A;
    ListNode* curr=A;
    while(curr!=NULL){
        if(curr->val==0){
            swap(curr->val,count->val);
            count=count->next;
        }
        curr=curr->next;
    }
    return A;
}
