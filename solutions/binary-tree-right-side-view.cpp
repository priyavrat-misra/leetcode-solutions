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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        
        queue<TreeNode*> q;
        vector<int> ans;
        TreeNode* f = nullptr;
        q.push(root);
        while (!q.empty()) {
            vector<int> lvl;
            int len = q.size();
            while (len--) {
                f = q.front();
                lvl.push_back(f -> val);
                q.pop();
                if (f -> left)
                    q.push(f -> left);
                if (f -> right)
                    q.push(f -> right);
            }
            ans.push_back(lvl.back());
        }
        return ans;
    }
};
