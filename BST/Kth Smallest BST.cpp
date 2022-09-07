//https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=1
//TRAVERSE inorder way, since it gives ascending order, increment counter, when u reach kth node
//return it
int solve(BinaryTreeNode<int>* root,int k,int& i){
    if(root==NULL){
        return -1;
    }
    //left
    int left = solve(root->left,k,i);
    if(left !=-1){ //need to return if not null
        return left;
    }
    //node
    i++;
    if(i==k){
        return root->data;
    }
    //right
    int right= solve(root->right,k,i);
    
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    return solve(root,k,i);
}
