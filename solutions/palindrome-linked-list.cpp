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
    ListNode* l = nullptr;
    ListNode* reverseList(ListNode* head) {
        if (head && head -> next) {
            l = reverseList(head -> next);
            head -> next -> next = head;
            head -> next = nullptr;
            return l;
        }
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head -> next)
            return true;
        
        ListNode list(-1, head);
        ListNode *t = head, *mid = &list;
        while (t && t -> next) {
            mid = mid -> next;
            t = t -> next -> next;
        }
        
        mid -> next = reverseList(mid -> next);
        
        t = mid = mid -> next;
        while (head != mid) {
            if (head -> val != t -> val)
                return false;
            head = head -> next;
            t = t -> next;
        }
        
        return true;
    }
};
