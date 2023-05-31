//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// n this optimized code, we maintain a HashMap called sumMap where the
// key is the cumulative sum encountered so far, and the value is the index at which the sum occurred.
// If the current sum is already present in the sumMap, it means that the subarray between the previous occurrence of the same sum and the 
// current index has a sum of zero. So, we update the maxLength if the length of this subarray is larger.
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int maxx = 0;
        unordered_map<int,int> mp;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=A[i];
             // If the current sum is zero, update the maxLength.
            if(sum==0){
                maxx = i+1;
            }
            
            if(mp.find(sum)!=mp.end()){
                maxx = max(maxx,i-mp[sum]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxx;
    }
    
};
