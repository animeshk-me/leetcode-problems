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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        while(temp != NULL) {
            temp->val *= -1;
            temp = temp->next;
        }
        temp = headB;
        while(temp != NULL && temp->val > 0)
            temp = temp->next;
        ListNode *temp2 = headA;
        while(temp2 != NULL) {
            temp2->val *= -1;
            temp2 = temp2->next;
        }
        return temp;
    }
};