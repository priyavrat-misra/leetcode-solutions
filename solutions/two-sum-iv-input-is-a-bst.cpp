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
    void inorderTraversal(TreeNode* root, vector<int>& v) {
        if (root) {
            inorderTraversal(root -> left, v);
            v.push_back(root -> val);
            inorderTraversal(root -> right, v);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorderTraversal(root, v);
        vector<int>::iterator i = v.begin(), j = v.end() - 1;
        while (i < j) {
            if (*i + *j < k)
                ++i;
            else if (*i + *j > k)
                --j;
            else
                return true;
        }
        return false;
    }
};
