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
    void preorder(TreeNode* root, bitset<10>& path, int& ans) {
        if (!root -> left && !root -> right) {
            path.flip(root -> val);
            if (path.count() < 2)
                ++ans;
            path.flip(root -> val);
            return;
        }
        path.flip(root -> val);
        if (root -> left)
            preorder(root -> left, path, ans);
        if (root -> right)
            preorder(root -> right, path, ans);
        path.flip(root -> val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        bitset<10> path(0);
        preorder(root, path, ans);
        return ans;
    }
};
