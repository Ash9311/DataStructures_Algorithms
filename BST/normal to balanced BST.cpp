//https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

//perform inORder traversal and get the data in asc order. and then using binary search logic
//construct a tree out of it

void inOrder(TreeNode<int>* root,vector<int> &inorderVal){
    if(root==NULL){
        return;
    }
    inOrder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inOrder(root->right,inorderVal);
}
//construct bst out of inOrder data
TreeNode<int>* inOrderToBST(int s,int e,vector<int> inOrderVal){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inOrderVal[mid]);
    root->left=inOrderToBST(s,mid-1,inOrderVal);
    root->right = inOrderToBST(mid+1,e,inOrderVal);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inOrderVal;
    inOrder(root,inOrderVal); //to get data in asc order
    int n = inOrderVal.size();
    return inOrderToBST(0,n-1,inOrderVal);
    
}
