//https://practice.geeksforgeeks.org/problems/common-elements1132/1/#
//create 3 hash iterate through each of them and hash it, and then iterate through any one of the hashes and see if any first element is
//common in all three hashes
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> result;
            unordered_map<int,int>mpA;
            unordered_map<int,int>mpB;
            unordered_map<int,int>mpC;
            
          for(int i=0;i<n1;i++){
                  mpA[A[i]]++;
          }
         
           for(int i=0;i<n2;i++){
                  mpB[B[i]]++;
          }
          
           for(int i=0;i<n3;i++){
              mpC[C[i]]++;
          }
          
          for(auto it: mpA){
              if(mpA[it.first] and mpB[it.first] and mpC[it.first]){
                  result.push_back(it.first);
              }
          }
          
          sort(result.begin(),result.end());
         
          return result;
            
        }
};
