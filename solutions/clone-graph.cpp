/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cp;

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        if (!cp.count(node)) {
            cp[node] = new Node(node -> val);
            for (Node* neighbor : node -> neighbors)
                cp[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
        return cp[node];
    }
};
