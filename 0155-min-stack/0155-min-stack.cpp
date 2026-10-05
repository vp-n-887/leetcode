class MinStack {
public:

   stack<int> s;
   stack <int> mins;

    MinStack() {
    }
    
    int min(int x,int y)
    {
        return (x>y)?y:x;
    }

    void push(int value) {
        s.push(value);

        if(mins.empty()){mins.push(value);}

        else
        {
            int x=min(mins.top(),value);
            mins.push(x);
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }

    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */