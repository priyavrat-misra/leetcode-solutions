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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || head && !head -> next)
            return head;
        
        int len = 1;
        ListNode* tail = head;
        while (tail -> next) {
            ++len;
            tail = tail -> next;
        }
        k %= len;
        k = len - k;
        while (k--) {
            tail -> next = head;
            head = head -> next;
            tail = tail -> next;
            tail -> next = nullptr;
        }
        return head;
    }
};
