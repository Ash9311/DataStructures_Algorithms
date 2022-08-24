//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
//maintain a map of horizontal distance and top node and a queue of pair of node,hd. first push root to queue.
//pop the font node and hd. and then include only 1 node data which belongs to the same hd. and then proceed with
//inserting left and right nodes to the queue
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> topNode; //pair of horizontal distance and top node
        queue<pair<Node*,int>> q; //int represents horizontal distance
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;
           
            if(!topNode[hd]){ //only 1 value shd be present since it hides others
                topNode[hd]=frontNode->data;
            }
            
            if(frontNode->left){ //proceed with remaining nodes
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto it: topNode){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};








#2 approach 


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
