// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
//get the count of nodes first and then check if tree is a complete binary tree and ismAxOrder
int countNode(struct Node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

bool isCBT(struct Node* root,int index,int totalCount){
    if(root==NULL){ //if its null then its a heap
        return true;
    }
    if(index>=totalCount){ //boundary condition check
        return false;
    }
    else{
        bool left = isCBT(root->left,2*index+1,totalCount); //check for left and right nodes recursively
        bool right = isCBT(root->right,2*index+2,totalCount);
        return (left and right);
    }
}

bool isMaxOrder(struct Node* root){//only if its CBT ,this function gets called
    //leaf node check
    if(root->left==NULL and root->right==NULL){
        return true;
    }
    if(root->right==NULL){ //only right child can be NULL in case of CBT
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left and right and (root->data>root->left->data and root->data>root->right->data ));
    }
}

class Solution {
  public:
    bool isHeap(struct Node* root) {
        int index=0;
        int totalCount = countNode(root);
        if(isCBT(root,index,totalCount) and isMaxOrder(root)){
            return true;
        }
        else{
            return false;
        }
    }
};
