/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node -> next;
        *node = *next;
        delete next;
    }
};
/**
 * class Solution {
 * public:
 *     ListNode* copy(ListNode* node) {
 *         if (!node -> next) {
 *             delete node;
 *             return nullptr;
 *         }
 *         node -> val = node -> next -> val;
 *         node -> next = copy(node -> next);
 *         return node;
 *     }
 *     
 *     void deleteNode(ListNode* node) {
 *         copy(node);
 *     }
 * };
 */
