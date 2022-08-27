//https://practice.geeksforgeeks.org/problems/k-sum-paths/1
//maintain a vector to store path,also maintain a variable count, push the root data first and recursively traverse
//after that check for path sum
class Solution{
    
    private:
    void solve(Node* root,int k,int &count,vector<int> path){
        if(root==NULL){
            return;
        }
        path.push_back(root->data); //push the current data to check fr sum
        
        solve(root->left,k,count,path); //traverse left and right recursively
        solve(root->right,k,count,path);
        
        //path sum check, so using this we are checking sum from a node in bottom up mannner in 
        //that respective path
        
        int size = path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==k){
            count++;
            }            
        }
        path.pop_back(); //backtrack to explore others
    }
    
  public:
    int sumK(Node *root,int k)
    {
        int count=0;
        vector<int> path;
        solve(root,k,count,path);
        return count;
    }
};
