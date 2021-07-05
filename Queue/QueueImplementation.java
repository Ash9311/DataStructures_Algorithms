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
        if(isFull()){
            System.out.println("Queue is Full");
        }
        else{
            if(front==-1){
                front=0;
            }
            rear++;
            items[rear]=element;
            System.out.println("Inserted element "+element);
        }
    }
    
    int deQueue(){
        int element;
        if(isEmpty()){
            System.out.println("Queue is Empty");
            return -1;
        }
        else{
            element = items[front];
            if(front>=rear){
                front=-1;
                rear=-1;
            }
            else{
                front++;

            }
            System.out.println("Deleted->"+element);
            return element;
        }   
    }

    void display(){
        int i;
        if(isEmpty()){
            System.out.println("Queue is Empty");
        }
        else{
            System.out.println("Front Index->"+front);
           
            for(i=front;i<=rear;i++){
                System.out.print(items[i]+" ");
            }
             System.out.println("Rear Index->"+rear);
        }
    }
    public static void main(String[] args) {
    Queue q = new Queue();

    // deQueue is not possible on empty queue
    q.deQueue();

    // enQueue 5 elements
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // 6th element can't be added to because the queue is full
    q.enQueue(6);

    q.display();

    // deQueue removes element entered first i.e. 1
    q.deQueue();

    // Now we have just 4 elements
    q.display();

  }

}