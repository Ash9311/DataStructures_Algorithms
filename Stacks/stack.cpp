#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void Display();
};

void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL){       //if stack is full node will not be created
        std::cout << "Stack is Full" << std::endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    int x;
    if(top==NULL){
        std::cout << "Stack is Empty\n" << std::endl;
    }
    else{
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display(){
    Node *p=top;
    while(p!=NULL){
        std::cout << p->data<<" " << std::endl;
        p=p->next;
    }
}

int main() {
	// your code goes here
	Stack stk;
	
	stk.push(10);
	stk.push(20);
	stk.push(30);
	
	stk.Display();
	stk.pop();
	stk.Display();
		
	return 0;
}
