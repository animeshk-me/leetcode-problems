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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        ListNode* save = head;
        ListNode* n_save = nullptr;
        while(save != nullptr) {
            n_save = save->next;
            save->next = temp;
            temp = save;
            save = n_save;
        }
        return temp;
    }
};