//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
//https://www.youtube.com/watch?v=2BdY9fixMrM&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&index=7

//User function Template for C++
//first check if left of root(curr) is present. if yes mark thas as predecessor and traverse towards right
//until its null. once u reach the border link that node to curr's right. and then make curr's right point to curr's left
//after that move curr ahead towards right.(need to dry run in order to understand). and curr's left must be made NULL
//after that our Binary tree gets converted into ta linked list.

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left){ //check if left exists
                Node* predecessor = curr->left; //mark it as predecessor
                while(predecessor->right){ //traverse through right of predecessor until its null
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;  //link predecessor right to curr's right
                curr->right = curr->left; //remove right link and make it point to left
                curr->left = NULL; //need to make left part null inorder to form a Linked list
            }
            curr = curr->right; //now that right link is targeted to left,move curr ahead
        }
        
    }
};

//T.C - O(N) ,SC - O(1)
