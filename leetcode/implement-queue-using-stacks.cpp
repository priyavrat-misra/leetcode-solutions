class MyQueue {
private:
    stack<int> l, r;
public:
    MyQueue() {}
    
    void push(int x) {
        l.push(x);
    }
    
    int pop() {
        int t = peek();
        r.pop();
        return t;
    }
    
    int peek() {
        if (r.empty())
            while (!l.empty()) {
                r.push(l.top());
                l.pop();
            }
        return r.top();
    }
    
    bool empty() {
        return l.empty() and r.empty();
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
