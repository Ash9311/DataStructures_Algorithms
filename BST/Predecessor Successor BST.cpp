
//https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
//first find the key, while keeping track of potential pred and succ. Once key is found
//traverse through right and left subtree finding pred and succ
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    //inOrder trversal of BST is ascending order, so when u normally traverse BST
    //value that comes later in inOrder can appear first.
   BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;
    while(temp->data!=key){
        if(temp->data<key){
            pred = temp->data; //save the value, it can be the potential ans
            temp = temp->right;
        }
        else{
            succ = temp->data;
            temp = temp->left;
        }
    }
    //inorder predecessor is the highest value in left subtree 
    //draw a tree diagram and perform inOrder, will understand the why
    //predecessor
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree!=NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    //successor is the min value in right sub tree
    //successor
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree!=NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int,int> res = make_pair(pred,succ);
    return res;
}
