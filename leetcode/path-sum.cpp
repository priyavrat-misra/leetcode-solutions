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
    bool hasPathSum(TreeNode* root, int& targetSum, int sumSoFar = 0) {
        if (root) {
            sumSoFar += root -> val;
            if (!root -> left && !root -> right && sumSoFar == targetSum)
                return true;
            return hasPathSum(root -> left, targetSum, sumSoFar)
                || hasPathSum(root -> right, targetSum, sumSoFar);
        }
        return false;
    }
};
