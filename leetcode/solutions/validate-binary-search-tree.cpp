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
    bool isValidBST(TreeNode* root, TreeNode* low = NULL, TreeNode* high = NULL) {
        if (!root)
            return true;
        if (low && low -> val >= root -> val ||
            high && high -> val <= root -> val)
            return false;
        return isValidBST(root -> left, low, root)
            && isValidBST(root -> right, root, high);
    }
};
