//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#


struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
  
  //maintain a vector and traverse through all the nodes, see if it is odd or even and insert even first, 
  //once we get the required data in the vector then replace original head values with those
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
         Node *res = new Node(-1);
        Node *curr = res;
        vector<int> ds;
        Node *ptr1 = head; //to check for even
        Node *ptr2 = head; //to check for odd
        Node *ptr3 = head; //for final
        while(ptr1!=NULL){
            if(ptr1->data%2==0){
              ds.push_back(ptr1->data);
            }
             ptr1=ptr1->next;
        }
            while(ptr2!=NULL){
            if(ptr2->data%2!=0){
            ds.push_back(ptr2->data);
             
            }
            ptr2=ptr2->next;
        }
        int i=0;
        
        while(ptr3!=NULL){
            ptr3->data = ds[i];
            ptr3 = ptr3->next;
            i++;
        }
        return head;
        
    }
};
