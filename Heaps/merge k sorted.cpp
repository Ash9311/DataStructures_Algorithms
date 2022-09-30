//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//use PQ And push all first elements of all arrays and then perform pop operation on top and create next node.
#include <bits/stdc++.h>

class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare> minHeap;
    //step 1 : insert first elements of all arrays
    for(int i=0;i<k;i++){
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    
    //step 2: pop top elements from heap . create the next node and push it to heap
    while(minHeap.size()>0){
        node *temp = minHeap.top(); //store it as we need it
        ans.push_back(temp->data);
        minHeap.pop();
        
        int i = temp->i;
        int j = temp->j;
        
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1); //create new node for next element and push it to heap
            minHeap.push(next);
        }
    }
    return ans;
}
