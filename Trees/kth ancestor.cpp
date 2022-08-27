//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

//first push the node into the vector and then traverse recursively. once you reach the bottom with all path nodes
//in the vector. check for the condition and update the ans if true.

int ans=-1;

 void solve(Node* root,int k,int node,vector<int> ds){
    if(root==NULL){
        return;
    }
    ds.push_back(root->data); //push the current root data for tracking purpose
    
    solve(root->left,k,node,ds); //traverse recursively first till the end
    solve(root->right,k,node,ds);
    int n = ds.size();
    if(root->data==node){
        if((n-k-1)>=0){ //make sure that kth ansistor exists
            ans = ds[n-k-1];
        }
        else{
            ans=-1;
        }
       
    }
    ds.pop_back(); //backtrack and got to parent tree to try out other combinations
    
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> ds;
    solve(root,k,node,ds);
    return ans;
}
