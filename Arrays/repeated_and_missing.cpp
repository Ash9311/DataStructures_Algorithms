//https://www.interviewbit.com/problems/repeat-and-missing-number-array/discussion/p/simple-solution-using-space-o-n-and-linear-time/227374/491

make a hash, and check for repeated and missing 

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    //unordered_map<int,int> mp;
    
    vector<int> res(A.size()+1,0);
    
    for(int i=0;i<A.size();i++){
        res[A[i]]++;
    }

   int repeated,missing;
    for(int i=1;i<=A.size();i++){
        if(res[i]>1){
            repeated=i;
        }
        if(res[i]==0){
            missing = i;
        }
    }
    
    return {repeated,missing};
}
