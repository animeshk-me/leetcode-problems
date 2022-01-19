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
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        if(head == NULL)
            return NULL;
        while(1) {
            slow = slow->next;
            if(fast->next == NULL || fast->next->next == NULL)
                return NULL;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        cout << slow->val << endl;
        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};