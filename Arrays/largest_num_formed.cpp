//https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1/#

sort it using a comparator which sorts based on concatenation

class Solution{
public:
	
	static bool comp(string a,string b){
	    return a+b>b+a;
	}
	
	string printLargest(vector<string> &arr) {
	   string result ="";
	   sort(arr.begin(),arr.end(),comp); //sorting string based on their string concatenation
	   for(string s : arr){
	       result += s;
	   }
	    return result;
	    
	}
};
