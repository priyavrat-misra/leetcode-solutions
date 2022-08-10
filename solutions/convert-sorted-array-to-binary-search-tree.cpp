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
    TreeNode* build(vector<int>& nums, int begin, int end) {
        if (end <= begin)
            return nullptr;
        int mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = build(nums, begin, mid);
        root -> right = build(nums, mid + 1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};
