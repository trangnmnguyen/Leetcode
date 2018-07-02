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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next && n == 1) return NULL;
        
     	ListNode* first = head;
     	ListNode* second = head;

     	for(int i = 0; i <= n; i++) second = second->next;
     	while(second->next) {
     		first = first->next;
     		second = second->next;
     	}
     	cout << first->val << " " << second->val;
        first->next = second;
        
     	return head;   
    }
};