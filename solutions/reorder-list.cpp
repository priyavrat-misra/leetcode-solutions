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
    void reorderList(ListNode* head) {
        if (head && !head -> next)
            return;
        
        ListNode *t1, *t2;
        t1 = t2 = head;
        while (t2 && t2 -> next) {
            t1 = t1 -> next;
            t2 = t2 -> next -> next;
        }
        stack<ListNode*> stk;
        t2 = t1;
        while (t2) {
            stk.push(t2);
            t2 = t2 -> next;
        }
        ListNode* t3 = head;
        while (t3 != t1) {
            t2 = t3 -> next;
            t3 -> next = stk.top();
            stk.pop();
            t3 = t3 -> next;
            t3 -> next = t2;
            t3 = t3 -> next;
        }
        t3 -> next = nullptr;
    }
};