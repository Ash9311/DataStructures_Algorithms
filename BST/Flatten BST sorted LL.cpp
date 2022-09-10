//https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

//get the ascending order via inorder traversal store the data. and then create new treeNode, traverse through stored
//inorder data and mark left as null and right as next node
void solve(TreeNode<int>* root,vector<int> &inorderVal){
    if(root==NULL){
        return;
    }
    solve(root->left,inorderVal);
    inorderVal.push_back(root->data);
    solve(root->right,inorderVal);
}
//T.C - O(N)  S.C - O(N)
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>inorderVal;
    solve(root,inorderVal);
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot; //pointer for new treeNode
    int n = inorderVal.size();
    for(int i=1;i<n;i++){ 
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]); //create a new and store the inorder data
        curr->left = NULL; //curr is pointing to prev node,make left child as NULL and right as curr node in inorder
        curr->right = temp;
        curr = temp; //move curr forward
    }
    curr->left = NULL; //last node's left and right must be NULL
    curr->right = NULL;
    return newRoot;
}

//#2 approach TLE
// get the ascending order via inorder traversal. and then traverse through stored
// inorder data and mark left as null and right as next node
void solve(TreeNode<int>* root,vector<TreeNode<int>*> &inorder){
    if(root==NULL){
        return;
    }
    solve(root->left,inorder);
    inorder.push_back(root);
    solve(root->right,inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int>*>inorder;
    solve(root,inorder);
    int i=0;
    for(i=0;i<inorder.size()-1;i++){ //make left child as NULL and right as next node in inorder
        inorder[i]->left = NULL;// thus it gets converted to sorted Linked list
        inorder[i]->right = inorder[i+1];
    }
    inorder[i]->left = NULL; //last node's left and right must be NULL
    inorder[i]->right = NULL;
    return inorder[0];
}
