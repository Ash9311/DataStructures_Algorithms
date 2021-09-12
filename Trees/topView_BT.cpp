class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    map<int,pair<int,int>> m; // distance , pair of level and root data
    
    void helper( Node *root,int distance,int level){
        if(root==NULL){
            return;
        }
        if(m.find(distance)==m.end() || m[distance].first>level){ //map doesnt contain distance or has same distance and the current level is lesser than the earlier visited node. 
            m[distance].first = level;
            m[distance].second = root->data;
        
        }
        helper(root->left,distance-1,level+1);
        helper(root->right,distance+1,level+1);
        
    }
    
    
    vector<int> topView(Node *root)
    {
       vector<int> v;
       m.clear();
       helper(root,0,0);
       for(auto it: m){
           v.push_back(it.second.second);
       }
       return v;
       
    }
    

};
