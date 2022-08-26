//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
//keep the track of maxLen,maxSum, , recursive traverse through all nodes and add up sum and count len for
//that path. when u reach the end for that path(root==NULL), check the condition and update if yes.
class Solution
{
    private:
    void solve(Node* root,int sum,int &maxSum,int len,int &maxLen){
        if(root==NULL){
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len==maxLen){//if len is equal then take maxSum as tie breaker
                maxSum=max(maxSum,sum);
            }
            return;
        }
        sum+=root->data;
        len++;
        solve(root->left,sum,maxSum,len,maxLen);
        solve(root->right,sum,maxSum,len,maxLen);
    }
    
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len=0;
        int maxLen=0;
        int sum=0;
        int maxSum=INT_MAX;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
    }
};
