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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head and head -> next) {
            if (head -> val == head -> next -> val)
                head = deleteDuplicates(head -> next);
            else
                head -> next = deleteDuplicates(head -> next);
        }
        return head;
    }
};
