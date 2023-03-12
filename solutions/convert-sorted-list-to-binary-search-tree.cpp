class Solution {
public:
    TreeNode* buildBST(int* a, int n) {
        if (n) {
            int m = n / 2;
            TreeNode* root = new TreeNode(a[m]);
            root -> left = buildBST(a, m);
            root -> right = buildBST(a + m + 1, n - m - 1);
            return root;
        }
        return nullptr;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        
        vector<int> arr;
        while (head)
            arr.push_back(head -> val), head = head -> next;
        
        return buildBST(&arr[0], arr.size());
    }
};