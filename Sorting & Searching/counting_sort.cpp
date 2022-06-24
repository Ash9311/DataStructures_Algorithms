//https://practice.geeksforgeeks.org/problems/counting-sort/1/#

//hash all the alphabets according to their ancii value, we will get getting sorted string once we iterate throgh all

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        int count[26]={0};
        int n = arr.size();
        string result = "";
        for(int i=0;i<n;i++){
            count[arr[i]-'a']++; //ascii of alphabets starts ar 96 so we are subtracting to get from 0
        }
        
        for(int i=0;i<26;i++){
            while(count[i]>0){ //for repeated chars
                result+=char(i+'a');
                count[i]--;
            }
        }
        return result;
        
    }
};
