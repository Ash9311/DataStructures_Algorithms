//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//declare variables of those 3 given num count it and then update the data of the node in ascending order

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int zero=0,one=0,two=0;
        Node *curr = head;
        
        while(curr!=NULL){
            if(curr->data==0){
                zero++;
            }
            else if(curr->data==1){
                one++;
            }
            else{
                two++;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr!=NULL){
            if(zero>0){
                curr->data = 0;
                zero--;
            }
            else if(one>0){
                curr->data = 1;
                one--;
            }
            else{
                
                curr->data=2;
            }
            curr = curr->next;
        }

        return head;
        
        
        
    }
};
