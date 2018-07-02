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
    bool hasCycle(ListNode *head) {
        ListNode* tmp = head;
        while(head) {
        	head = head->next;
        	if(head == tmp) return true;
        }
        return false;
    }
};