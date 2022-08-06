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
    vector<string> res;
    
    void dfs(TreeNode* root, string path) {
        if (!root)
            return;
        if (!root -> left && !root -> right) {
            res.push_back(path + to_string(root -> val));
            return;
        }
        dfs(root -> left, path + to_string(root -> val) + "->");
        dfs(root -> right, path + to_string(root -> val) + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};
