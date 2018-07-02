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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* newList;
    	ListNode* head = newList;
        while(l1 || l2) {
        	if(!l1 && l2) {
        		newList = l2;
        		newList = newList->next;
        		l2 = l2->next;
        		continue;
        	} 

        	if(!l2 && l1) {
        		newList = l1;
        		newList = newList->next;
        		l1 = l1->next;
        		continue;
        	}

        	if(l1->val > l2->val) {
	    		newList = l2;
	    		
	    		l2 = l2->next;
	    	} else if(l1->val < l2->val) {
	    		newList = l1;
	    		l1 = l1->next;
	    	} else if(l1->val == l2->val) {
	    		newList = 
	    	}
            cout << newList->val << " ";
        }
        return head;
    }
};