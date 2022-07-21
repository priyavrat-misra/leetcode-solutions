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
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (head -> next == tail)
            return head;
        
        ListNode* l = reverseList(head -> next, tail);
        head -> next -> next = head;
        head -> next = tail;
        return l;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head -> next || left == right)
            return head;
        
        ListNode* end = head;
        while (right--)
            end = end -> next;
        
        if (left == 1)
            return reverseList(head, end);
        
        ListNode* begin = head;
        left -= 1;
        while (--left)
            begin = begin -> next;
        
        begin -> next = reverseList(begin -> next, end);
        return head;
    }
};
