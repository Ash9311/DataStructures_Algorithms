//https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//T.C - O(N)
//create a class 'info' consisting of all the required data. recursively traverse fr left and right. set
//data fr currNode based on left,right result. chevk if condition is satisfied and recursion will handle.
//update the ans to check fr max
************************************************************/
  class info{ //declare class for required info
      public:
        int maxi;
        int mini;
        bool isBST;
        int size;
    };
  info solve(TreeNode<int>* root, int &ans){
      if(root==NULL){
          return {INT_MIN,INT_MAX,true,0}; //return data fr NULL case
      }
      info left = solve(root->left,ans); //traverse recursively
      info right = solve(root->right,ans);     
      info currNode; //declare info fr curr node after knowing its lft,right info
      currNode.size = left.size + right.size + 1;
      currNode.maxi = max(root->data,right.maxi);
      currNode.mini = min(root->data,left.mini);
      if((root->data > left.maxi and root->data < right.mini) and left.isBST and right.isBST){ //condition check
          currNode.isBST = true;
      }
      else{
          currNode.isBST = false;
      }
      //update ans
      if(currNode.isBST){
          ans = max(ans,currNode.size);
      }
      return currNode;
  }  

int largestBST(TreeNode<int>* root) 
{
   int maxSize=0;
    info temp = solve(root,maxSize); //maxSize is passed by reference and therefore we get maxSize in entire BT ,as it updates for all
    return maxSize;
}
