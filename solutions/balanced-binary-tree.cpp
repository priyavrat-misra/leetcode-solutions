class Solution {
public:
    int dfsHeight(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = dfsHeight(root -> left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = dfsHeight(root -> right);
        if (rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};
