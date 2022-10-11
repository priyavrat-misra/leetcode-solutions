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
    vector<int> inorder;
    void traverseInorder(TreeNode* root) {
        if (root) {
            traverseInorder(root -> left);
            inorder.push_back(root -> val);
            traverseInorder(root -> right);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        traverseInorder(root);
        vector<int>::iterator i = inorder.begin();
        vector<int>::iterator j = inorder.end() - 1;
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
