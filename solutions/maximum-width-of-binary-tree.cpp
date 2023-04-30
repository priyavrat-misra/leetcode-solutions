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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int start = q.front().second;
            int end = q.back().second;
            res = max(res,end-start + 1);

            int cnt = q.size();
            pair<TreeNode*, int> f;
            for (int i = 0; i < cnt; ++i) {
                f = q.front();
                unsigned idx = f.second - start;
                q.pop();

                if (f.first -> left)
                    q.push({f.first -> left, 2 * idx + 1});
                
                if (f.first -> right)
                    q.push({f.first -> right, 2 * idx + 2});
            }
        }
        return res;
    }
};
