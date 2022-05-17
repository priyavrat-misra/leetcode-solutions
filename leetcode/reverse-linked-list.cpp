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
private:
    ListNode* l = nullptr;
public:
    ListNode* reverseList(ListNode* head) {
        if (head and head -> next) {
            l = reverseList(head -> next);
            head -> next -> next = head;
            head -> next = nullptr;
            return l;
        }
        return head;
    }
};
