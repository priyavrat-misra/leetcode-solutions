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
    ListNode* head;
    Solution(ListNode* head) {
        this -> head = head;
        srand(clock());
    }
    
    int getRandom() {
        int n = 0;
        ListNode* t = head;
        while (t)
            ++n, t = t -> next;
        n = rand() % n;
        t = head;
        while (n--)
            t = t -> next;
        return t -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
