//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool isLeaf(Node *root){
    return !root->left and !root->right;
}

void addLeftBoundary(Node *root,vector<int> &res){
   Node *curr = root->left;
   while(curr){
       if(!isLeaf(curr)){
           res.push_back(curr->data);
       }
       if(curr->left){
       curr = curr->left;
       }
       else {
           curr=curr->right;
       }
   }
   
}

void addRightBoundary(Node *root,vector<int> &res){
    Node *curr=root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else {
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
   
}

void addLeaves(Node *root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left){
    addLeaves(root->left,res);
    }
    if(root->right){
    addLeaves(root->right,res);
    }
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        
        if(!root){
            return res;
        }
        
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
    }
};




#2 little different approach

struct Node
{
    int data;
    Node* left, * right;
}; */
//first take the leftboundary but dont consider leaf nodes and then take the leaf nodes and then take rightbounday
//while backtracking since we need right in reverse. and also handle condition where left node is empty and 
//right node is non empty, in that case right node will act as left boundar
class Solution {
    
    private:
    void leftBoundary(Node *root,vector<int> &result){
        
         if(root==NULL){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            return;
        }
        result.push_back(root->data);
        if(root->left){ //since there can be a case where left node isnt there and right nodes left will be a boundary
            leftBoundary(root->left,result);
        }
        else{
            leftBoundary(root->right,result);
        }
        
        
    }
    
    private:
    void rightBoundary(Node *root,vector<int> &result){
         if(root==NULL){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            return;
        }
       if(root->right){ //since there can be a case where right node isnt there and left nodes right will be a boundary
        rightBoundary(root->right,result);
       }
       else{
           rightBoundary(root->left,result);
       }
         result.push_back(root->data);
    }
    
    private:
    void leafNodes(Node *root,vector<int> &result){
         if(root==NULL){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            result.push_back(root->data);
            return;
        }
        leafNodes(root->left,result);
        leafNodes(root->right,result);
    }
    
    
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int> result;
        if(root==NULL){
            return result;
        }
         if(root->left==NULL and root->right==NULL){ //if there is only 1 node
            result.push_back(root->data);
            return result;
        }
        result.push_back(root->data); //insert root and then go for left,right
        leftBoundary(root->left,result);
        leafNodes(root,result);
        rightBoundary(root->right,result);
        
        return result;
    }
};
