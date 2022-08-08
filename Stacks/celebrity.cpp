//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// first push all indexes into the stack and then keep popping 2 elements till stack size is 1  and check who knows who ,if a knows b then push b or vice versa
//once you get that potential candidate check for row and col counts
class Solution 
{
    private:
    bool knows(vector<vector<int> > &M,int a,int b){
        
            if(M[a][b]==1){
                return true;
            }
            return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        //push indexes into the stack
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        //pop 2 elements and check who knows who ,if a knows b then push b or vice versa
        while(st.size()>1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(M,a,b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        int candidate = st.top();
        //single element left in the stack is a possible celebrity
        //check for count in row and col if hez a celeb then row should be full zero and col should have n-1 ones
        
        int zeroCount=0;
        
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0){
                zeroCount++;
            }
        }
        
        if(zeroCount!=n){
            return -1;
        }
        //col check
        
        int oneCount=0;
        
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1){
                oneCount++;
            }
        }
        if(oneCount!=n-1){
            return -1;
        }
        
        return candidate;
    }
};
