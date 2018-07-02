class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *result = head;
        int extra = 0; 
        int sum = 0; 
        while(l1 || l2 || extra) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra; 
            extra = sum/10;
            result->next = new ListNode(sum % 10);
            result = result->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head->next;
    }
};