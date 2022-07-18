//https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=1&category[]=Recursion&sortBy=submissions

//use recursive approach, in the second recursion change from,aux,to to aux,to,from, and in the end just return count

Move n-1 discs from source to dest using aux
Move a disc from source to aux
move n-1 discs from dest to aux using source

class Solution{
    public:
    long long toh(int N, int source, int dest, int aux) {
        
        if(N>0){
            toh(N-1,source,aux,dest);
            cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<dest<<"\n";
            toh(N-1,aux,dest,source);
        }
        return pow(2,N)-1;
    }
