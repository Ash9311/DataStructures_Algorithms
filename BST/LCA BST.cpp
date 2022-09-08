//https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=1

//in case of BST its different. first go to subtree where LCA CAN LIE
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root==NULL){
        return NULL;
    }
    if(root->data<P->data and root->data<Q->data){//indicates that LCA is in right subtree
        return LCAinaBST(root->right,P,Q);
    }
     if(root->data>P->data and root->data>Q->data){//indicates that LCA is in left subtree
        return LCAinaBST(root->left,P,Q);
    }
   return root;//if root->Data > P and root->Data <Q then the root is LCA (AND vice versa)
    
}


//iterative

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
         if(root->data<P->data and root->data<Q->data){//indicates that LCA is in right subtree
           root = root->right;
    }
     else if(root->data>P->data and root->data>Q->data){//indicates that LCA is in left subtree
        root = root->left;
    }
        else{
            return root;
        }
    }
    
    
}
