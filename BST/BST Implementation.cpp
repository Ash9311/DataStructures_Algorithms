#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

void preorder(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL); // so that we get to know if level has been completed

  while (!q.empty()) {
    Node *temp = q.front();

    q.pop();

    if (temp == NULL) { // purana lvl complete traverse ho chuka heh
      cout << endl;     // next line to represent level
      if (!q.empty()) { // if there are child nodes present we need to push NULL
                        // at end for reference
        q.push(NULL);
      }
    } else { // these nodes will be in the queue when we go for next level
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

Node *insertIntoBST(Node *root, int data) {
  if (root == NULL) {
    root = new Node(data);
    return root;
  }
  if (data > root->data) {
    root->right = insertIntoBST(root->right, data);
  } else {
    root->left = insertIntoBST(root->left, data);
  }
  return root;
}

void takeInput(Node *&root) {
  int data;
  cin >> data;

  while (data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

int minValue(Node *&root) {
  Node *temp = root;
  while (temp->left != NULL) {
    temp = temp->left;
  }
  return temp->data;
}

int maxValue(Node *&root) {
  Node *temp = root;
  while (temp->right != NULL) {
    temp = temp->right;
  }
  return temp->data;
}

int InorderPredecessor(Node *&root, int key,vector<int> &ds) {
  if (root == NULL) {
    return -1;
  }  
  InorderPredecessor(root->left, key,ds);
    if (root->data==key) {
        if(ds.size()==0){
            return -1;
        }
        return ds[ds.size()-1];
  }
  ds.push_back(root->data);
  InorderPredecessor(root->right, key,ds);
}

Node* deleteFromBST(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child case
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        
        //1 child case
        //left child case
        if(root->left!=NULL and root->right==NULL){
            Node* temp = root->left; //save left node address since we are deleting current root
            delete root;
            return temp; 
        }
        //right child case
         if(root->left==NULL and root->right!=NULL){
            Node* temp = root->right; //save left node address since we are deleting current root
            delete root;
            return temp; 
        }
        //2 child case
        if(root->left!=NULL and root->right!=NULL){
            int mini = minValue(root->right); //we have an option of taking min from right and max from left
            root->data = mini; // replace current node with mini 
            root->right = deleteFromBST(root->right,mini); //delete mini which was in right subtree(recursively it will happen, it will go down to 1 child case)
            return root;
        }
        
    }
    else if(root->data<val){
        root->left = deleteFromBST(root->right,val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->left,val);
        return root;
    }
}

int main() {
  Node *root = NULL;
  cout << "Enter data to create BST:" << endl;
  takeInput(root);
  cout << "Printing the BST in level order" << endl;
  levelOrderTraversal(root);
  cout << endl << "Printing the BST in In order" << endl;
  inorder(root);
  cout << endl << "Min value is ";
  cout << minValue(root);
  cout << endl << "Max value is ";
  cout << maxValue(root);
  cout << endl << "InOrderPredecessor is ";
    vector<int> ds;
    
  cout<<InorderPredecessor(root, 10,ds);
  
  //deletion
  root = deleteFromBST(root,30);
  
  cout << "Printing the BST in level order" << endl;
  levelOrderTraversal(root);
  cout << endl << "Printing the BST in In order" << endl;
  inorder(root);
  cout << endl << "Min value is ";
  cout << minValue(root);
  cout << endl << "Max value is ";
  cout << maxValue(root);
  cout << endl << "InOrderPredecessor is ";

    
  cout<<InorderPredecessor(root, 10,ds);
  
  return 0;
}
