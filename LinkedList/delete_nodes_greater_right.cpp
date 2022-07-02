//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1/#
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
  
  //traverse through the LL, if you find a node lesser than its next node, then make current node same as next node value and then 
  //skip the next node.
  
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node *curr = head;
        Node *temp;
        while(curr->next!=NULL){
            if(curr->data<curr->next->data){
               temp = curr;
               temp->data = temp->next->data; //trick of making the current data same as next and delete the next
               temp->next = temp->next->next;
               curr = head; //since the order has changed ,need to start from head again
               
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
    
};

//recursive
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        Node *res = compute(head->next);
        
        if(res->data > head->data){
            return res;
        }
        else{
            head->next = res;
            return head;
        }
    }
};
