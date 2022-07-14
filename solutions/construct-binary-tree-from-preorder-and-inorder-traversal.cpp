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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_idx = 0;
        return build(preorder, inorder, root_idx, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& root_idx, int left, int right) {
        if (left > right)
            return nullptr;
        
        int pivot = left;
        while (inorder[pivot] != preorder[root_idx])
            ++pivot;
        
        TreeNode* root = new TreeNode(preorder[root_idx]);
        ++root_idx;
        root -> left = build(preorder, inorder, root_idx, left, pivot - 1);
        root -> right = build(preorder, inorder, root_idx, pivot + 1, right);
        return root;
    }
};
