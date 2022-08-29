/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
//first check the 0th index of preOder and then find the same element in Inorder, get the index of it and using
//that we can find left and right nodes
class Solution{
    
    private:
    int findPosition(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    private:
    Node* solve(int in[],int pre[],int &index,int inOrderStart,int inOrderEnd,int n){
        if(index>=n or inOrderStart > inOrderEnd){
            return NULL;
        }
        int element = pre[index++];//take the index from preorder and move it forward
        Node *root = new Node(element); //create a new node out of it
        int position = findPosition(in,element,n); //find that node's position in inorder, so that we get left and right info
        
        root->left = solve(in,pre,index,inOrderStart,position-1,n);
        root->right = solve(in,pre,index,position+1,inOrderEnd,n);
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
       
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};
