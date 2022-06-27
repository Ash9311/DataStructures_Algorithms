
//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


class Solution
{
    public:
   
    void deleteNode(Node *del)
    {
       if(del==NULL){
           return;
       }
       //must delete 2 : {1,2,3,4}
       del->data = del->next->data;
       //{1,3,3,4}
       del->next = del->next->next;
       //{1,3,4}
    }
};
