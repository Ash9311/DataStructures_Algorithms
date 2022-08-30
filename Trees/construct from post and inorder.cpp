//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
//first check the n-1th index of postOrder and then find the same element in Inorder, get the index of it and using
//that we can find left and right nodes(i.e whatever node is in left to what we search in inorder will be the left, same for right)

void createMapping(int in[],map<int,int> &nodeToIndex,int n){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}


Node *solve(int in[],int post[],int &postOrderIndex,int inOrderStart,int inOrderEnd,int n,map<int,int> &nodeToIndex){
    if(postOrderIndex<0 or inOrderStart>inOrderEnd){
        return NULL;
    }
    int element = post[postOrderIndex--]; //starting from end since its postOrder
    Node *root = new Node(element); //since we are building a new tree out of inOrder and PostOrder
    int position = nodeToIndex[element]; //find that node's position in inorder, so that we get left and right info
    //since v r starting from end, we must traverse right node first
    root->right = solve(in,post,postOrderIndex,position+1,inOrderEnd,n,nodeToIndex); //will understand when tree dia is drawn
    root->left = solve(in,post,postOrderIndex,inOrderStart,position-1,n,nodeToIndex);
    
    return root;
}


//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex=n-1;
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    Node* ans = solve(in,post,postOrderIndex,0,n-1,n,nodeToIndex);
    return ans;
}
