
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 //
//traverse recursively, NULL is returned as the ans if the root which you are traversing is null, 
//if you found the data that you are looking for, simply return that node.
//if one of leftAns or rightAns is null return the non null.
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL){
           return NULL;
       }
       if(root->data==n1 or root->data==n2){
           return root;
       }
       Node* leftAns = lca(root->left,n1,n2); //traverse left and right
       Node* rightAns = lca(root->right,n1,n2);
       
       if(leftAns!=NULL and rightAns!=NULL){ //return non null root
           return root;
       }
       else if(leftAns!=NULL and rightAns==NULL){
           return leftAns;
       }
        else if(leftAns==NULL and rightAns!=NULL){
           return rightAns;
       }
       return NULL;
    }
};
