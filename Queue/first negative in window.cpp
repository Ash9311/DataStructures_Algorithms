//create a dequeue, first process window of size K. and then implement for the remaining elements
//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
     deque<long long int>dq;
     vector<long long> ans;
     //process first window of k size
     for(int i=0;i<K;i++){
         if(A[i]<0){
         dq.push_back(i);
         }
     }
     
     //store ans of first k sized window
     if(dq.size()>0){
         ans.push_back(A[dq.front()]);
     }
     else{
         ans.push_back(0);
     }
     
     //process remaining elements
     for(int i=K;i<N;i++){
         //pop the element which is not a part of current window
         if(!dq.empty() and i-dq.front()>=K){
             dq.pop_front();
         }
         //addition
         if(A[i]<0){
             dq.push_back(i);
         }
         //ans store
         if(dq.size()>0){
             ans.push_back(A[dq.front()]);
         }
         else{
             ans.push_back(0);
         }
     }
     return ans;
     
 }
