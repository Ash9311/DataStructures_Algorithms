//https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0

//create BST in pre order manner, before that check if it meets BST eligibility
BinaryTreeNode<int>* solve(vector<int> &preorder,int mini,int max,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini or preorder[i]>max){ //BST eligibility check
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);//create node and increment i
    root->left = solve(preorder,mini,root->data,i);//note the change of mini,max for left,right
    root->right = solve(preorder,root->data,max,i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int max = INT_MAX;
    int i=0;
    return solve(preorder,mini,max,i);
    
}
