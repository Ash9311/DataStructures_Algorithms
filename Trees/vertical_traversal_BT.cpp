
//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
class Solution
{
    public:
    
     //mark an imaginary horizontal line like .... -2 -1 0 1 2....with main root pointing 0. make a map and queue
     //for tracking and traversal.
    
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
           map<int,map<int,vector<int>>> nodes;
 //Horizontal dist^     ^level      ^list of nodes
       queue<pair<Node*,pair<int,int>>> q; //queue for level order traversal and tracking purpose
       //                      ^horizontal dist,level of nodes    
       vector<int> ans;
       
       if(root==NULL){
           return ans;
       }
       q.push(make_pair(root,make_pair(0,0)));//hd,lvl is 0 for root node
       
       while(!q.empty()){
           pair<Node*,pair<int,int>> temp = q.front(); //take all node from queue and process it
           q.pop();
           Node* frontNode = temp.first;
           int hd = temp.second.first;
           int lvl = temp.second.second;
           
           nodes[hd][lvl].push_back(frontNode->data);
           
           if(frontNode->left!=NULL){
               q.push(make_pair((frontNode->left),make_pair(hd-1,lvl+1)));
           }
            if(frontNode->right!=NULL){
               q.push(make_pair((frontNode->right),make_pair(hd+1,lvl+1)));
           }
           
       }
       
       for(auto i:nodes){
           for(auto j:i.second){
               for(auto k:j.second){
                   ans.push_back(k);
               }
           }
       }
       return ans;
    }
};














//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
        void traverseTree(TreeNode *root,int d,map<int,vector<int>> &mp){
            if(root==NULL){
                return;
            }
            mp[d].push_back(root->val);
            traverseTree(root->left,d-1,mp);
            traverseTree(root->right,d+1,mp);
        }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        int d=0;
        traverseTree(root,d,mp);
        for(auto p:mp){
           res.push_back(p.second);
        }
        return res;
    }
};
