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
    ListNode* partition(ListNode* head, int x) {
        ListNode node_p1, node_p2;
        ListNode *p1 = &node_p1, *p2 = &node_p2;
        while (head) {
            if (head -> val < x)
                p1 = p1 -> next = head;
            else
                p2 = p2 -> next = head;
            
            head = head -> next;
        }
        p2 -> next = nullptr;
        p1 -> next = node_p2.next;
        return node_p1.next;
    }
};
