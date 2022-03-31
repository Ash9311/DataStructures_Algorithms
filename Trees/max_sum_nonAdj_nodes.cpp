//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/#_=_
class Solution{
    
    class Pair{
        public:
        int inc;
        int exc;
    };
    
  public:
  
  Pair solve(Node* root){
      Pair p;
      if(root==NULL){
          p.inc=p.exc=0;
          return p;
      }
      Pair Left = solve(root->left);
      Pair Right = solve(root->right);
      
      p.inc = root->data + Left.exc + Right.exc;
      p.exc = max(Left.exc,Left.inc) + max(Right.exc,Right.inc);
      return p;
  }
  

  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        Pair res = solve(root);
        return max(res.inc,res.exc);
        
    }
};
