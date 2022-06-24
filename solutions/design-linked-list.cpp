struct Node {
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node *next) : val(val), next(next) {}
};

class MyLinkedList {
public:
    Node *head = nullptr, *tail = nullptr;
    MyLinkedList() {}
    
    int get(int index) {
        Node *t = head;
        while (index-- && t)
            t = t -> next;
        
        return t ? t -> val : -1;
    }
    
    void addAtHead(int val) {
        head = new Node(val, head);
        if (!tail)
            tail = head;
    }
    
    void addAtTail(int val) {
        tail = tail ? (tail -> next = new Node(val)) : new Node(val);
        if (!head)
            head = tail;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node *t = head;
        while (--index && t)
            t = t -> next;
        if (t) {
            t -> next = new Node(val, t -> next);
            if (!t -> next -> next)
                tail = t -> next;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            Node *t = head;
            head = head -> next;
            delete t;
            return;
        }
        
        Node *t = head;
        while (--index && t)
            t = t -> next;
        if (t && t -> next) {
            Node *d = t -> next;
            t -> next = t -> next -> next;
            delete d;
            if (!t -> next)
                tail = t;
        }
    }
    
    void deleteLinkedList(Node *head) {
        if (head) {
            deleteLinkedList(head -> next);
            delete head;
        }
    }
    
    ~MyLinkedList() {
        deleteLinkedList(head);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
