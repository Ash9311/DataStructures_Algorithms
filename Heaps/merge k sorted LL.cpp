//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//create a minHeap and push all elements into it. when we pop it. it will be in asc order. Process it 
#include<queue>
class compare{
    public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data > b->data;
    }
};
//T.C -> O(KlogK) + O(n*k logk)
Node<int> *mergeKLists(vector<Node<int>*> &listArray)
{
   priority_queue<Node<int>*,vector<Node<int>*>, compare> minHeap;
    int k = listArray.size();
    if(k==0){
        return NULL;
    }
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    //step 1:
    for(int i=0;i<k;i++){ //O(KlogK)
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }
    }
    while(minHeap.size()>0){ //store top element and pop it. and then process
        Node<int>* top = minHeap.top();
        minHeap.pop();
        
        if(top->next!=NULL){//push the next linked node to PQ
            minHeap.push(top->next);    //O(n*k logk)
        }
        if(head==NULL){ //ans LL is empty, create one
            head = top;
            tail = top;
        }
        else{ //insert at LL
            tail->next = top;
            tail = top;
        }
        
    }
    return head;
}
