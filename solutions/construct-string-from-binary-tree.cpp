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
    void parenthesize(TreeNode* root, string& res) {
        res += to_string(root -> val);
        if (root -> left) {
            res.push_back('(');
            parenthesize(root -> left, res);
            res.push_back(')');
        }
        if (root -> right) {
            if (!root -> left)
                res += "()";
            res.push_back('(');
            parenthesize(root -> right, res);
            res.push_back(')');
        }
    }
    
    string tree2str(TreeNode* root) {
        string res;
        parenthesize(root, res);
        return res;
    }
};
