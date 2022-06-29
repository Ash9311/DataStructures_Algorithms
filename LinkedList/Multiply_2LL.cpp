//https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1/#

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

//use multiply by 10 logic on each digit starting from index 0 to merge all node data value of a linked list and then multiply it with other LL;

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long result;
  long long temp1=0,temp2=0,mod= 1000000007;
  while(l1!=NULL){
      temp1 = (temp1*10 + l1->data)%mod;
      l1 = l1->next;
  }
   while(l2!=NULL){
      temp2 = (temp2*10 + l2->data)%mod;
      l2 = l2->next;
  }
  result = (temp1*temp2)%mod;
  return result;
}
