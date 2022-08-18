//https://www.youtube.com/watch?v=5NiXlPrLslg&t=2430s

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); //so that we get to know if level has been completed

    while(!q.empty()){
        node *temp = q.front();
        
        q.pop();

        if(temp==NULL){ //purana lvl complete traverse ho chuka heh
            cout<<endl; //next line to represent level
            if(!q.empty()){ //if there are child nodes present we need to push NULL at end for reference
                q.push(NULL);
            }
        }
         else{ //these nodes will be in the queue when we go for next level
                cout<<temp->data<<" ";
                if(temp->left){ 
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
    }


}

void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//take data of root, create a node out of it, push it to the queue. take left and right data as input and create a node if its not
//null and push it to the queue. continue until queue is empty.
void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}

//take the data for root node, create a node and then recursively create left and right
node* buildTree(node *root){
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data ==-1){
        return NULL;
    }
    cout<<"enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main(){
    node* root = NULL;

    //creating a tree
    // root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"Printing level order traversal output "<<endl;
    // levelOrderTraversal(root);

    // cout<<"Inorder traversal is ";
    // inorder(root);

    // cout<<"preorder traversal is ";
    // preorder(root);

    // cout<<"postorder traversal is ";
    // postorder(root);

 buildFromLevelOrder(root);
 levelOrderTraversal(root);
   //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    return 0;
}
