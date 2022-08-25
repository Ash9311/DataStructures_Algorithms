//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//maintain a map of horizontal distance and bottom node data and a queue of pair of node,hd. first push root to queue.
//pop the font node and hd. and then keep on overwriting bottomNode data which belongs to the same hd. and then proceed with
//inserting left and right nodes to the queue
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> bottomNode; //pair of horizontal distance and bottom node data
        queue<pair<Node*,int>>q; //int is hd
        q.push(make_pair(root,0));//pair of root and horizontal distance
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            bottomNode[hd]=frontNode->data; //this will overwrite the node data for that hd, thus while traversing
            //we will get deepest nodes for that horizontal distance
            
            if(frontNode->left){ //continue traversing
                q.push(make_pair(frontNode->left,hd-1));
            }
             if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto it: bottomNode){
            ans.push_back(it.second);
        }
        return ans;
    }
};




//#2 using recursion

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
