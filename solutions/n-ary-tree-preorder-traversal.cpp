/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return {};
        
        vector<int> ans;
        stack<Node*> s;
        Node* t = nullptr;
        s.push(root);
        while (!s.empty()) {
            t = s.top();
            s.pop();
            ans.push_back(t -> val);
            for (vector<Node*>::reverse_iterator it = (t -> children).rbegin(); it != (t -> children).rend(); ++it)
                s.push(*it);
        }
        return ans;
    }
};
