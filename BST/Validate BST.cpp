//https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0
//if root is null its true, validate the currrent Node and then traverse recursively if both left and right is true return true else false
//T.C - O(N) S.C - O(H)
bool isBST(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }
    //there are 2 boundaries defined, min and max for a node, starts with -infy to +infy
    //then it depends on its parent node.
    if(root->data >= min && root->data<=max){ //check if current node is valid
        bool left = isBST(root->left,min,root->data); //when going left its parent will be the max
        bool right = isBST(root->right,root->data,max);//for right traversal, min is parent
        return left && right;
    }
    else{
    return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root,INT_MIN,INT_MAX);
}
