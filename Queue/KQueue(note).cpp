//https://www.youtube.com/watch?v=_gJ3to4RyeQ&t=6268s
#include <iostream>
#include<queue>
#include<vector>
using namespace std;

//we have a queue with k windows, to optimize space we have arranged it in mixed order but we linked all window elements.
//while enqueue or dequeue we optimally changed the freespot as soon as element get popped out
class kQueue{
    public:
        int n;
        int k;  
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n,int k){
            this->n = n;
            this->k = k;
            front = new int[k]; 
            rear = new int[k];
            next = new int[n];
            arr = new int[n];
            int freeSpot = 0;  
            for(int i=0;i<k;i++){
                front[i] = -1;
                rear[i] = -1;
            }
            for(int i=0;i<n;i++){
                next[i] = i+1;
            }
            next[n-1] = -1;

        }
        //data of different windows are not side by side. but they are linked
        void enqueue(int data,int qn){
            //overflow check
           if(freeSpot==-1){
            cout<<"No empty space is present"<<endl;
            return;
           }       

           //find first free index
           int index = freeSpot;

           //update freespot
            freeSpot = next[index];

            //check whether it is first element for that window
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the previous
                next[rear[qn-1]]=index;
            }
            //update next
            next[index] = -1;
            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;

        }

        int dequeue(int qn){
            //check underflow
            if(front[qn-1]==-1){
                cout<<"Queue underflow"<<endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badao
            front[qn-1] = next[index];

            //freeslots ko manage karo, since we popped first one, free slot will be updated
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];

        }

};

 int main(){
    
    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    return 0;
 }
