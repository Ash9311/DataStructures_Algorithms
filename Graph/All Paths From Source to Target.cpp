//https://leetcode.com/problems/all-paths-from-source-to-target/

//dfs will do

class Solution {
public:
    
    void dfs(int curr,vector<int> &path,vector<vector<int>> &paths,vector<vector<int>> &graph){
        path.push_back(curr);
        if(curr==graph.size()-1){
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for(auto it: graph[curr]){
            dfs(it,path,paths,graph);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0,path,paths,graph);
        return paths;
            
    }
};
