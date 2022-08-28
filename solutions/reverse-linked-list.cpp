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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head -> next)
            return head;
        ListNode *a = nullptr, *b = head, *c;
        while (b) {
            c = b -> next;
            b -> next = a;
            a = b;
            b = c;
        }
        return a;
    }
};

/**
 * class Solution {
 * public:
 *     void reverse(ListNode* t, ListNode** head) {
 *         if (t -> next == nullptr) {
 *             *head = t;
 *             return;
 *         }
 *         reverse(t -> next, head);
 *         t -> next -> next = t;
 *         t -> next = nullptr;
 *     }
 * 
 *     ListNode* reverseList(ListNode* head) {
 *         if (!head || !head -> next)
 *             return head;
 * 
 *         reverse(head, &head);
 *         return head;
 *     }
 * };
 */

