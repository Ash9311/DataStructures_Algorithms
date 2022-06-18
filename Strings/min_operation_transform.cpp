//https://practice.geeksforgeeks.org/problems/b6b3297ccfb1ad5f66a9c2b92979170417adf114/1/#

//first check if both the strings are having same length and chars. initialize 2 pointers at the last index and decrement them 
//according to the condition shown.ptrB is moved only if there is a match. And we need not modify the string, we just need the count.

class Solution{

    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	unordered_map<char,int> mp;
    	
    	if(A.length()!=B.length()){
    	    return -1;
    	}
    	
    	int n = A.length();
    	
    	for(int i=0;i<n;i++){ //using this approach we can detect if there is a mismatch in chars
    	    mp[A[i]]++;
    	    mp[B[i]]--;
    	}
    	
    	for(auto it: mp){
    	    if(it.second!=0){
    	        return -1; //char mismatch found
    	    }
    	}
    	
    	int result=0;
    	int ptrA=n-1,ptrB=n-1;
    	while(ptrA>=0){ //if pointer index chars dont match insert the char in the beginning of the string. that way we get the count
    	    if(A[ptrA]!=B[ptrB]){
    	        result++; 
    	    }
    	    else{
    	      ptrB--;    
    	    }
    	    ptrA--;
    	    
    	}
    	return result;
    }
};
