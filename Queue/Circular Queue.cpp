//https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=1
//intialize front and rear to -1 and while inserting first element make them 0
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    //there are 4 cases,
    ///1)when queue is full, 2)when its empty and ur pushing first element,3)when rear is at end, push it to start 4) normal enqueue
    bool enqueue(int value){
        //check whether queue is full
        if((rear==size-1 and front==0) or (rear==(front-1)%(size-1))){
            //cout<<"Queue is full"<<endl;
            return false;
        }
       else if(front==-1){
           rear=0;
           front=0;
       }
        else if(rear==size-1 and front!=0){
            rear=0; //to maitain cyclic nature
        }
        else{
            rear++; //normal case
        }
        //push inside the queue
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1){ 
           // cout<<"Queue is empty";
            return -1;                
        }
        int ans = arr[front];
         arr[front]=-1;
        //single element case
        if(front==rear){
           front=rear=-1;
        }
        else if(front==size-1){
            front = 0; //to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }
};
