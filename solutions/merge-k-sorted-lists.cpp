/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeLists(ListNode*& left, ListNode*& right) {
        ListNode mergedList;
        ListNode* t = &mergedList;
        while (left && right) {
            if (left -> val < right -> val)
                t -> next = left, left = left -> next;
            else
                t -> next = right, right = right -> next;

            t = t -> next;
        }
        while (left)
            t -> next = left, left = left -> next, t = t -> next;
        while (right)
            t -> next = right, right = right -> next, t = t -> next;

        return mergedList.next;
    }

    ListNode* divideAndConquer(ListNode** lists, int n) {
        if (n == 0)
            return nullptr;
        if (n == 1)
            return *lists;
        int m = n / 2;
        ListNode* left = divideAndConquer(lists, m);
        ListNode* right = divideAndConquer(lists + m, n - m);
        return mergeLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return divideAndConquer(&lists[0], lists.size());
    }
};