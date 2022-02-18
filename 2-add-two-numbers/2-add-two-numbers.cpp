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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        normalize(l1, l2);
        ListNode* x = l1, *y = l2;
        ListNode* head = nullptr;
        ListNode* temp = head;
        
        int carry = 0;
        while(x != nullptr) {
            int val = x->val + y->val + carry;
            if(head == nullptr) {
                head = new ListNode(val % 10);
                temp = head;
            }
            else {
                temp->next = new ListNode(val % 10);
                temp = temp->next;
            }
            x = x->next;
            y = y->next;
            carry = val / 10;
        }
        if(carry > 0)
            temp->next = new ListNode(carry);
        
        return head;
        
    }
    
    
    void normalize(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1->next != nullptr && temp2->next != nullptr) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1->next == nullptr && temp2->next == nullptr)
            return;
        ListNode* larger = temp1->next != nullptr ? temp1 : temp2; 
        ListNode* smaller = temp1->next == nullptr ? temp1 : temp2; 
        while(larger->next != nullptr) {
            smaller->next = new ListNode(0);
            smaller = smaller->next;
            larger = larger->next;
        }
    }
};