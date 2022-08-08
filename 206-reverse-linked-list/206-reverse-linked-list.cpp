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
        ListNode* head_next=head, *temp=nullptr;
        while(head_next != nullptr) {
            head_next = head->next;
            head->next = temp;
            temp = head;
            head = head_next;
        }
        return temp;
    }
};