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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root,nodes);
        return nodes;
    }
    
    void postorder(TreeNode* root,vector<int>& nodes){
        if(!root){
            return;
        }
        
        postorder(root->left,nodes);
        postorder(root->right,nodes);
        nodes.push_back(root->val);
    }
};
------------------------------------------
    //iterative

    struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
public:
     vector<int> solve(Node* root) {
        vector<int> ans;
         if(!root) return ans;
        stack<Node*> s1;
        s1.push(root);

        while(!s1.empty()){//push node's children into the stack and process each of them
            Node* node = s1.top();
            s1.pop();
            ans.push_back(node->data); //store .it but it will be in reversed post order manner
            if(node->left){
                s1.push(node->left);
            }
            if(node->right){
                s1.push(node->right);
            }

        }
        reverse(ans.begin(),ans.end()); //since its in reversed post order
        return ans;
     }
};
