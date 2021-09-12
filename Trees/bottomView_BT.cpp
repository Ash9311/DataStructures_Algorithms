class Solution {
  public:
  
    map<int,pair<int,int>> mp;
    
    void helper(Node *root,int distance,int level){
        if(root==NULL){
            return;
        }
        if(mp.find(distance)==mp.end() || mp[distance].first<=level){
            mp[distance].first = level;
            mp[distance].second = root->data;
        }
        helper(root->left,distance-1,level+1);
        helper(root->right,distance+1,level+1);
        
    }
    
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> v;
        mp.clear();
        helper(root,0,0);
        for(auto it: mp){
            v.push_back(it.second.second);
        }
        return v;
    }
};
