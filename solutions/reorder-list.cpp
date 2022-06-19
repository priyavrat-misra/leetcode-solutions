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
        while (t1) {
            stk.push(t1);
            t1 = t1 -> next;
        }
        t1 = head;
        while (true) {
            t2 = t1 -> next;
            t1 -> next = stk.top();
            stk.pop();
            if (stk.empty()) {
                t1 = t1 -> next;
                break;
            }
            t1 = t1 -> next;
            t1 -> next = t2;
            t1 = t1 -> next;
            if (t2 == stk.top())
                break;
        }
        t1 -> next = nullptr;
    }
};
