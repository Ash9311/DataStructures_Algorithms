//https://leetcode.com/problems/add-two-numbers/
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
class Solution {
public:
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        vector<int> v2;
        ListNode* L1 = l1;
        
        while(L1!=NULL){
             v1.push_back(L1->val);
            L1=L1->next;
        }
        
         while(l2!=NULL){
            v2.push_back(l2->val);
            l2=l2->next;
        }
        
        string str1,str2;
        
        for(int i=0;i<v1.size();i++){
            str1+=to_string(v1[i]);
        }
        
         for(auto it: v2){
            str2+=to_string(it);
        }
        
        long long sum = stoll(str1)+stoll(str2);
        ListNode* result = new ListNode(-1);
        ListNode *res = result;
        string summ = to_string(sum);
        ListNode* L2 = l1;
       
        for(int i=0;i<summ.size() and result!=NULL;i++){
            ListNode* temp = new ListNode(sum%10);
            result->next = temp;
            result=temp;
            cout<<sum%10<<" ";
            sum=sum/10;
        }
        
        return res->next;
    }
};
