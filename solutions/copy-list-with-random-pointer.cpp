/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* t = head;
        while (t) {
            m[t] = new Node(t -> val);
            t = t -> next;
        }
        t = head;
        while (t) {
            m[t] -> next = m[t -> next];
            m[t] -> random = m[t -> random];
            t = t -> next;
        }
        return m[head];
    }
};
