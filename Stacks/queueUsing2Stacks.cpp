//https://leetcode.com/problems/implement-queue-using-stacks/submissions/
class MyQueue {
public:
    
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()){
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
    }
    
    int pop() {
        int front = s1.top();
        s1.pop();
        return front;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return  s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
