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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* h2 = head->next;
        ListNode* t1 = head;
        ListNode* t2 = h2;
        while(1) {
            t1->next = t2->next;
            if(t1->next == NULL)
                break;
            t1 = t1->next;
            t2->next = t1->next;
            if(t2->next == NULL)
                break;    
            t2 = t2->next;
        }
        t1->next = h2;
        return head;
    }
};