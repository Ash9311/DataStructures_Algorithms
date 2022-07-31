//https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111328/offering/1279905?leftPanelTab=0
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

class Stack
{
    //Write your code here
    int size;
    Node *head;
        
        public:
        Stack()
        {
            size=0;
            head = NULL;
        }        //Write your code here 
   

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        //Write your code here  
        return size==0;
    }

    void push(int data)
    {
        //Write your code here
        Node *n = new Node(data);
        n->next = head;
        head = n;
        size++;
    }

    void pop()
    {
        //Write your code here
        if(size>=1){
            head = head->next;
            size--;
        }
    }

    int getTop()
    {
        if(size>=1){
            return head->data;
        }
        else{
            return -1;
        }
    }
};
