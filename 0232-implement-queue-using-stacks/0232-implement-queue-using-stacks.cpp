class MyQueue {
public:
     stack<int> stack1;
        stack<int> stack2;
    MyQueue() {
        
        
    }
    
    void push(int x) {
         stack1.push(x);
        
    }
    
    int pop() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                throw out_of_range("Queue is empty. Cannot pop");
            }
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int topVal = stack2.top();
        stack2.pop();
        return topVal;
        
    }
    
    int peek() {
          if (stack2.empty()) {
            if (stack1.empty()) {
                throw out_of_range("Queue is empty. Cannot peek.");
            }
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    
        
    }
    
    bool empty() {
         return stack1.empty() && stack2.empty();
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