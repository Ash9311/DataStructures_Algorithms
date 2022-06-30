/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
//increase each node data of curr1 by 10000 so that we get to know when we traverse using curr2(since 1 node is common for both)

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node*,int>mp;
    Node* curr1 = head1;
    Node* curr2 = head2;
    
   while(curr1!=NULL){
       curr1->data+=10000;
       curr1 = curr1->next;
   }
   
    while(curr2!=NULL){
       if(curr2->data>1000){
           return curr2->data-10000;
       }
       curr2 = curr2->next;
   }
   
    return -1;
}
