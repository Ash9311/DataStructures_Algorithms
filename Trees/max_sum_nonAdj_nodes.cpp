//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/#_=_

//maintain a pair where 'first' includes current root data but not its direct children, 'second' doesnt
//include current root data but includes direct children,, so in second we can choose max between
//its's childs first and second

class Solution{
  public:
  pair<int,int> solve(Node* root){
      if(root==NULL){
          pair<int,int> p = make_pair(0,0);
          return p;
      }
      pair<int,int> left = solve(root->left); //traverse recursively first
      pair<int,int> right = solve(root->right);
      
      pair<int,int> res;
      res.first = root->data+left.second+right.second; //current root is being included, so its direct child cannot be included
      res.second = max(left.first,left.second) + max(right.first,right.second);//current is excluded, so we have option to choose both, so take max one
      return res;
  }

  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
      pair<int,int> ans = solve(root);
      return max(ans.first,ans.second);
    }
};





//2


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
