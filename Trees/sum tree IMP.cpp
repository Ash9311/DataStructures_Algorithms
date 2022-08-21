/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
//https://practice.geeksforgeeks.org/problems/sum-tree/1
// Should return true if tree is Sum Tree, else false

//make a pair of bool and int to check condition efficiently.write base condition. traverse recursively for
//left and right subtrees. check the condition and store the result in new pair called ans

class Solution
{
    
    private:
    pair<bool,int> isSumTreeFast(Node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left==NULL and root->right==NULL){
            pair<bool,int> p =make_pair(true,root->data);//returning true bcoz, condition didnt break as of now
            return p;
        }
        
        pair<bool,int> leftSumTree = isSumTreeFast(root->left); //traverse left and right recursively
        pair<bool,int> rightSumTree = isSumTreeFast(root->right);
        
        bool condition = root->data == leftSumTree.second + rightSumTree.second; //check condition
        pair<bool,int> ans;
        
        if(leftSumTree.first and rightSumTree.first and condition){
            ans.first = true;
            ans.second = 2*root->data; //since left and right values are equal
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};
