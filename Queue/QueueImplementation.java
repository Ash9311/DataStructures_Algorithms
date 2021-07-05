public class Queue{
    int SIZE = 5;
    int[] items = new int[SIZE];
    int front,rear;

    Queue(){
        front = -1;
        rear = -1;
    }

    boolean isFull(){
        if(front==0 && rear==SIZE-1){
            return true;
        }
        return false;
    }

    boolean isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }

    void enQueue(int element){
        if(isFull){
            System.out.println("Queue is Full");
        }
        else{
            if(front==-1){
                front=0;
            }
            rear++;
            iteam[rear]=element;
            System.out.println("Inserted element "+element);
        }
    }

    
}