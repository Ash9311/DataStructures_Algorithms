 //https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
 
 //check the NULL case first, recursively traverse left and right moving both nodes together, and then check
  //if all condition is true
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
       if(r1==NULL and r2==NULL){
           return true;
       }
       
       if(r1==NULL and r2!=NULL){
           return false;
       }
       
        if(r1!=NULL and r2==NULL){
           return false;
       }
       
       bool left = isIdentical(r1->left,r2->left);
       bool right = isIdentical(r1->right,r2->right);
       bool curr = r1->data == r2->data;
        if(left and right and curr){
           return true;
       }
      return false;
    }
};
