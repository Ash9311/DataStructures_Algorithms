//https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0
//store in order traversal value to get ascending order data, and then use 2 pointer approach
//to get the 2 sum
void solve(BinaryTreeNode<int>* &root,vector<int> &ds){
    if(root==NULL){
        return;
    }
    solve(root->left,ds);
    ds.push_back(root->data);
    solve(root->right,ds);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> ds;
    solve(root,ds);
    int i=0,j=ds.size()-1;
    int sum=0;
    while(i<j){ //2 pointer approach to get 2 sum
        sum=ds[i]+ds[j];
        if(sum==target){
            return true;
        }
        if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}
