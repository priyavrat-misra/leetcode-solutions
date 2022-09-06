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
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int len = q.size();
            vector<int> lvl(len);
            for (int i = 0; i < len; ++i) {
                Node* f = q.front();
                q.pop();
                lvl[i] = f -> val;
                for (Node* &child : f -> children)
                    q.push(child);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};
