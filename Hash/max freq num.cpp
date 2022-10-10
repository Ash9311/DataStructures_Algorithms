//https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//create a map. insert the values and find the max. and then return the num with least integer

int maximumFrequency(vector<int> &arr, int n)
{
    int maxx=-1;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        maxx = max(mp[arr[i]],maxx);
    }
   
    for(auto it:arr){ //find the num with least index
        if(mp[it]==maxx){
           maxx =it;
             break;
        }  
    }
    return maxx;
}
