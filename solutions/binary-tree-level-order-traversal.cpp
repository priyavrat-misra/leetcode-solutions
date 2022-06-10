/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> v;
        TreeNode* f = nullptr;
        q.push(root);
        int len;
        while (!q.empty()) {
            vector<int> lvl;
            len = q.size();
            for (int i = 0; i < len; ++i) {
                f = q.front();
                lvl.push_back(f -> val);
                q.pop();
                if (f -> left)
                    q.push(f -> left);
                if (f -> right)
                    q.push(f -> right);
            }
            v.push_back(lvl);
        }
        return v;
    }
};
