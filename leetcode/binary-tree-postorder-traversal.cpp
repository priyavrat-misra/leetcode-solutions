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
private:
    vector<int> t;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root) {
            postorderTraversal(root -> left);
            postorderTraversal(root -> right);
            t.push_back(root -> val);
        }
        return t;
    }
};
