//https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Node* reverseDLL(Node * head)
{
    //Your code here
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node *temp = NULL;
    Node *curr = head;
    while(curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;  //reversing   
        curr->next = temp;      //reversing
        curr = curr->prev; //since curr->prev is pointing to next node which we want to traverse
        
    }
    temp = temp->prev //temp is the new head, since its reversed
    return temp;
}

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
