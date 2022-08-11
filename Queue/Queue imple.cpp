//https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=1
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
            
public:
    Queue() {
        size = 100001;
        arr = new int[size]; //can be arr[size] too
        qfront =0;
        rear=0;
    }

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(rear==size){
            cout<<"Queue is full";
        }
        else{
        arr[rear] = data;
        rear++;
        }
    }

    int dequeue() {
        if(qfront==rear){
            return -1;
        }
        int ans = arr[qfront];
       arr[qfront] = -1;
        qfront++;
        if(qfront==rear){  //to save waste space..fr ex ["","",2,4] if both front and rear are pointing to 2
            qfront=0;
            rear=0;
        }
        return ans;
    }

    int front() {
        if(qfront==rear){
            return -1;
        }
        return arr[qfront];
    }
};
