struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
//https://practice.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1
  //since the lesser than and greater than condition occur alternatively, maintain a flag switching in phase, and depending on the condition
  //swap the 2 node data
  
  
class Solution
{
    public:
    
    
    void swap(Node *a,Node *b){
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
    
    Node *zigZag(Node* head)
    {
     // your code goes here
     Node *temp = head;
     int flag=0;
     while(temp->next){
         if(flag){
             if(temp->data < temp->next->data){
                 swap(temp,temp->next);
             }
             flag =0; 
         }
             else {
                 if(temp->data > temp->next->data){
                    swap(temp,temp->next);
                   
             }
              flag=1;     
             }
         temp = temp->next;
     }
     return head;
    }
};
