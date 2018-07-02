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
    ListNode* reverseList(ListNode* head) {
     	ListNode* cur = head;
     	ListNode* nextNode = head->next;
     	ListNode* prev = NULL;
     	while(cur) {
     		cur->next = prev;
     		ListNode* tmp = nextNode;
     		nextNode = nextNode->next;
     		prev = cur;
     		cur = tmp;
     	}
     	return cur;
    }
};