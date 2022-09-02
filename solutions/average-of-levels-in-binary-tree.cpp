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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while (!q.empty()) {
            double sum = 0.;
            int n = q.size(), count = n;
            TreeNode* f = nullptr;
            while (n--) {
                f = q.front();
                q.pop();
                sum += f -> val;
                if (f -> left)
                    q.push(f -> left);
                if (f -> right)
                    q.push(f -> right);
            }
            res.push_back(sum / count);
        }
        return res;
    }
};
