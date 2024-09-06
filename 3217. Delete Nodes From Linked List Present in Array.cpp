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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int maxv = 0;
        for (int v : nums) {
            maxv = std::max(maxv, v);
        }

        std::vector<bool> rem(maxv + 1, false);
        for (int v : nums) {
            rem[v] = true;
        }

        ListNode* h = new ListNode(0);
        ListNode* t = h;
        ListNode* p = head;

        while (p != nullptr) {
            if (p->val > maxv || !rem[p->val]) {
                t->next = p;
                t = p;
            }
            p = p->next;
        }

        t->next = nullptr;

        return h->next;
    }
};