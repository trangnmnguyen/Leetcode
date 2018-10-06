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
	ListNode* findEnd(ListNode* head, ListNode* nEnd) {
		ListNode* tmp = head;
		while(tmp->next != nEnd) {
			tmp = tmp->next;
		}
		return tmp;
	}

	void swapStart(ListNode* cur, ListNode* prev, ListNode* head, ListNode* end) {
		if(cur == head) {
			return;
		}

		if(prev != NULL) {
			prev->next = cur->next;
		}
		cur->next = head;
		head = cur;

		if(cur == end) {
			end = prev;
		}
		return;
	}

	void swapEnd(ListNode* cur, ListNode* prev, ListNode* head, ListNode* end) {
		if(cur == end) {
			return;
		}

		// if(cur == head) {
		// 	tmp = cur->next;
		// 	end->next = cur;
		// 	end = cur;
		// 	start = tmp;
		// 	return;
		// }

		if(prev != NULL) {
			prev->next = cur->next;
		}
		end->next = cur;
		end = cur;

		if(cur == head) {
			head = cur->next;
		}
	}

	int findSize(ListNode* head, ListNode* end) {
		int i = 0;
		ListNode* tmp = head;
		while(tmp != end->next) {
			tmp = tmp->next;
			i++;
		}
		return i;
	}

	ListNode* findPivot(ListNode* head, ListNode* end) {
		int pivot = rand() % findSize(head, end), i = 0;
		ListNode* tmp = head;
		while(i < pivot) {
			tmp = tmp->next;
			i++;
		}
		return tmp;
	}

	void quickSort(ListNode* head, ListNode* end, ListNode* pHead, ListNode* nEnd) {
		if(head == end || head == nEnd) return;
		ListNode* pivot = findPivot(head, end);
		ListNode* tmp = head, prev = pHead;

		while(tmp != nEnd) {
			if(tmp->val < pivot->val) {
				swapStart(tmp, prev, head, end);
			}
			if(tmp->val > pivot->val) {
				swapEnd(tmp, prev, head, end);
			}
			prev = tmp;
			tmp = tmp->next;
		}

		pHead->next = head;
		nEnd = end->next;

		quickSort(head, findEnd(head, pivot), pHead, pivot);
		quickSort(pivot->next, end, pivot, nEnd);
	}

    ListNode* sortList(ListNode* head) {
		quickSort(head, findEnd(head, NULL), NULL, end->next);
		return head;
    }
};