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
    ListNode* removeNthFromEnd(ListNode* head, int& n) {
        if (!head)
            return nullptr;
        
        head -> next = removeNthFromEnd(head -> next, n);
        --n;
        if (!n)
            return head -> next;
        
        return head;
    }
};

/**
 * class Solution {
 * public:
 *     ListNode* removeNthFromEnd(ListNode* head, int n) {
 *         if (head -> next == nullptr)
 *             return nullptr;
 *         
 *         ListNode *i, *j;
 *         i = j = head;
 *         while (n--)
 *             i = i -> next;
 *         if (i) {
 *             while (i -> next) {
 *                 i = i -> next;
 *                 j = j -> next;
 *             }
 *             j -> next = j -> next -> next;
 *         } else {
 *             head = head -> next;
 *         }
 *         
 *         return head;
 *     }
 * };
 */
