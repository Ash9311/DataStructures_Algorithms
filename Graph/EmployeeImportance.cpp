//https://leetcode.com/problems/employee-importance/submissions/
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        for(auto it: employees){
            mp[it->id]=it;
        }
        int sum=0;
        DFS(mp,id,sum);
        return sum;
    }
    
    void DFS(unordered_map<int,Employee*>&mp,int id,int&sum){
        sum+=mp[id]->importance;
        for(auto it:mp[id]->subordinates){
            DFS(mp,it,sum);
        }        
        }
    
};
