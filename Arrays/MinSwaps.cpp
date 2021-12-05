//https://practice.geeksforgeeks.org/problems/minimum-swaps/1

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   int n = nums.size(); 
	   pair<int,int> ap[n];

	   for(int i=0;i<n;i++){
	       ap[i].first = nums[i];
	       ap[i].second = i;
	   }
	   	sort(ap,ap+n);
	   vector<bool> visited(n,false);
	   int result =0;
	   for(int i=0;i<n;i++){
	       if(visited[i]==true or ap[i].second==i){
	           continue;
	       }
	       int curr = i;
	       int cycle=0;
	       while(!visited[curr]){
	           visited[curr]=true;
	           curr = ap[curr].second;
	           cycle+=1;
	       }
	       result +=cycle-1;
	   }
	   return result;
	}
};
