//https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
class Solution
{
public:
    
    void solve(vector<int> &arr,int N,int i,vector<int> &res,int sum){
        if(i==N){
            res.push_back(sum);
            return;
        }
        solve(arr,N,i+1,res,sum+arr[i]);
        solve(arr,N,i+1,res,sum);
    }
    

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        int sum=0;
        solve(arr,N,0,res,0);
       
        return res;
    }
};
