//https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1?page=1&category[]=Recursion&sortBy=submissions
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


//pass count as a reference and then recursively find the sum for the tree, increment the count
//if sum is equal to target
int solve(Node* root,int X,int &count){
    if(root==NULL){
        return 0;
    }
    int sum = root->data + solve(root->left,X,count) + solve(root->right,X,count);
    if(sum==X){
        count++;
    }
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count=0;
    solve(root,X,count);
	return count;
}



------------
  
  //void method
  
  void solve(Node* root,int X,int &count,int sum){
    if(root==NULL){
        return;
    }
    
    solve(root->left,X,count,sum);
 
    solve(root->right,X,count,sum);
    
    if(root->left and root->right){
        root->data +=root->left->data + root->right->data;
    }
    else if(root->left){
        root->data +=root->left->data;
    }
    else if(root->right){
        root->data+=root->right->data;
    }
      
    if(root->data==X){
        count++;
    }
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count=0;
	int sum=0;
    solve(root,X,count,sum);
	return count;
}
