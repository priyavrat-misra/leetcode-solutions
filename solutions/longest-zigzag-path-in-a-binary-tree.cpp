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
    int ans = 0;
    
    void dfs(TreeNode* root, int l, int r) {
        if (!root)
            return;
        ans = max(ans, l);
        ans = max(ans, r);
        dfs(root -> left, 0, l + 1);
        dfs(root -> right, r + 1, 0);
    }

    int longestZigZag(TreeNode* root) {
        int l = 0, r = 0;
        dfs(root, l, r);
        return ans;
    }
};
