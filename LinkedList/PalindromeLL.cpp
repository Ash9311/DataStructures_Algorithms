//https://leetcode.com/problems/palindrome-linked-list/
//traverse through the Linked list to get the count and add the elements to the vector. and then use 2 pointer approach to check whether its a palindrome.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *ptr1 = head;
        int count=0;
        vector<int> arr;
        while(ptr1!=NULL){
            count++;
            arr.push_back(ptr1->val);
            ptr1 = ptr1->next;
        }
        int i=0,j=count-1;
       for(int k=0;k<count/2;k++){
          
           if(arr[i]!=arr[j]){
               return false;
           }
           i++;
           j--;
       }
        return true;
    }
};
