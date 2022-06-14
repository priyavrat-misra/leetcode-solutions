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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};
        
        queue<Node*> q;
        vector<vector<int>> ans;
        Node* f = nullptr;
        int len;
        
        q.push(root);
        while (!q.empty()) {
            vector<int> lvl;
            len = q.size();
            for (int i = 0; i < len; ++i) {
                f = q.front();
                q.pop();
                lvl.push_back(f -> val);
                for (Node* &child : f -> children)
                    q.push(child);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};
