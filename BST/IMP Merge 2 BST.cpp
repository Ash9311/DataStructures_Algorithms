
//https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//find inoder of both bst and store it. we get both in asc order. after that merge both of the arrays and then create a BST out of it.
void inorder(TreeNode<int> *root,vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergeArrays(vector<int> &bst1,vector<int> &bst2){
    vector<int> mergedArray(bst1.size()+bst2.size());
    int n1=bst1.size();
    int n2 = bst2.size();
    int i=0,j=0,k=0;
    while(i<n1 and j<n2){// merging bst1,bst2 using 2 pointers
        if(bst1[i]<bst2[j]){
            mergedArray[k++]=bst1[i];
            i++;
        }
        else if(bst1[i]>bst2[j]){
            mergedArray[k++]=bst2[j];
            j++;
        }
        else{
             mergedArray[k++]=bst1[i];
             mergedArray[k++]=bst2[j];
            i++;
            j++;
        }
    }
    //add the remaining element of bst1 or bst2 (2 possibilities), 
    //either 1 of these will execute, coz 1 is full
    while(i<n1){
        mergedArray[k++]=bst1[i];
        i++;
    }
     while(j<n2){
        mergedArray[k++]=bst2[j];
        j++;
    }
    return mergedArray;
}

TreeNode<int>* inOrderToBST(int s,int e,vector<int> &inOrderVal){ //constructs BST out of sorted merged array
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inOrderVal[mid]);
    root->left=inOrderToBST(s,mid-1,inOrderVal);
    root->right = inOrderToBST(mid+1,e,inOrderVal);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //step1: store inorder
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    
    //step2: merge both arrays
    vector<int> mergedArray = mergeArrays(bst1,bst2); //merging both arrays
    
    //step3: construct BST out of merged sorted array
    return inOrderToBST(0,mergedArray.size()-1,mergedArray); //constructing BST out of it
    //T.C - O(N+M)   S.C - O(N+M)
}
