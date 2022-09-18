#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
      //  arr[0]=-1;
        size=0;
    }
    //T.C - O(logn)
     //first insert it at last and then place it in correct position.
  //heap property -> parent = index/2, Lchild = index*2 , Rchild = (index+1)*2;
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(size>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
               swap(arr[parent],arr[index]);
               index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"Noting to delete"<<endl;
            return;
        }

        //step1 : put last element into first index  O(1)
        arr[1] = arr[size];

        //step2 : remove last element  O(1)
        size--;
        int i=1;

        //step3: take root node to correct position O(logn)
        while(size>1){
            int leftIndex = 2*i;
            int rightIndex = 2*(i+1); 
            if(leftIndex < size and arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size and arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex ;
            }
            else{
                return;
            }
            
        }

    }

    
};



void heapify(int arr[],int n,int i){
    int largest = i;
    int left = i*2;
    int right = (2*i)+1;
    if(left<=n and arr[largest]<arr[left]){ //check if left and right child is larger, if yes then update,take care of boundary
        largest = left;  
    }
    if(right<=n and arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){ //if updated
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
//T.C -> O(nlogn)
void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){
    heap h;
    h.insert(50);
     h.insert(55);
      h.insert(53);
       h.insert(52);
        h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();

int arr[6] = {-1,54,53,55,52,50};
int n =5;
for(int i=n/2; i>0;i--){
    heapify(arr,n,i);
}
cout<<"Printing the array now"<<endl;
    heapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
