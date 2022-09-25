class MyCircularQueue {
public:
    int* q;
    int front = -1, rear = -1;
    const int size;
    
    MyCircularQueue(int k) : size(k) {
        q = new int[size];
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        else if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;
        
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        else if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
    
    ~MyCircularQueue() {
        delete[] q;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
