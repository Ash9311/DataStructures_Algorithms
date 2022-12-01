//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#


//use a recursive approach to traverse through all the paths without obstacles and maintain the string change(it is being passed by value)

class Solution{
    public:
    
    void findPath(vector<vector<int>> &m,string s,int n,int row,int col,vector<string> &result){
        if(row==n-1 and col==n-1){
            result.push_back(s);
            return;
        }
        //string is passed by value so after the current stack it gets cleared  
        if(row>=0 and col>=0 and row<n and col<n and m[row][col]==1){
            m[row][col]=2; //mark as visited notation
            findPath(m,s+"D",n,row+1,col,result);
            findPath(m,s+"L",n,row,col-1,result);
            findPath(m,s+"U",n,row-1,col,result);
            findPath(m,s+"R",n,row,col+1,result);
            m[row][col]=1//back track to explore new ones
            
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        if(m[0][0]==0 or m[n-1][n-1]==0){
            return result;
        }
        string s;
        findPath(m,s,n,0,0,result);
        return result;
    }
};
