//https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=1&category[]=Recursion&sortBy=submissions

//use recursive approach, in the second recursion change from,aux,to to aux,to,from, and in the end just return count
class Solution{
    public:
    long long toh(int N, int from, int to, int aux) {
        
        if(N>0){
            toh(N-1,from,aux,to);
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
            toh(N-1,aux,to,from);
        }
        return pow(2,N)-1;
    }
