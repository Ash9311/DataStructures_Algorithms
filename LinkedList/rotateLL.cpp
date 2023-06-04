
//store the value in the vector. shift if using another vector and put the value in the linked list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* ptr = head;
        vector<int> v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        int n = v.size();
        vector<int> v1(v.begin(),v.end());
        for(int i=0;i<n;i++){
            v1[(i+k)%n]=v[i];  //v1 represents shifted vector
           }
  int i=0;
 while(ptr!=NULL){ //put value of v1 into the Linked list
           ptr->val = v1[i]; 
            ptr = ptr->next;
            i++;
        }

        return head;
    }
};

-----------
  In this modified implementation, the algorithm counts the length of the linked list and adjusts k to be within the range of the list length. 
  It then performs the rotation by updating the connections between nodes. 
  Finally, it sets the new head of the rotated linked list and breaks the circular reference by setting curr->next to nullptr.
Please note that this implementation assumes the use of a singly linked list where each node has a next pointer.
  
  class Solution {
public:
   ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    ListNode* curr = head;
    int length = 1;
    while (curr->next != nullptr) {
        curr = curr->next;
        length++;
    }

    curr->next = head;  // Connect the last node with the head to form a circular linked list ,for temporary advantage

    k = k % length;
    int rotations = length - k;

    while (rotations > 0) {
        curr = curr->next;
        rotations--;
    }

    head = curr->next;
    curr->next = nullptr;  // Set the new end of the linked list, break the circular LL which has been set

    return head;
}
};
