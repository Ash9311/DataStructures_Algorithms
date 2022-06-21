//https://practice.geeksforgeeks.org/problems/print-diagonally4331/1

//first print upper left triangle of the matrix including the mid diagonal, after that start with lower portion in different for loop
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> result;
		for(int k=0;k<n;k++){ //upper portion including mid diagonal
		    int i=0;
		    int j=k;
		    while(j>=0){
		        result.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		
		for(int k=1;k<n;k++){ //lower portion
		    int i=k;
		    int j=n-1;
		    while(i<n){
		        result.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		return result;
	}

};
