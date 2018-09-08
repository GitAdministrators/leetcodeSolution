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
	ListNode* swapPairs(ListNode* head) {
		if (!head) return NULL;
		ListNode ** res = NULL;
		ListNode ** tmp = NULL;
		ListNode* fst = head;
		while (fst && fst->next)
		{
			ListNode* sec = fst->next;
			ListNode* nextfst = fst->next->next;
			if (res)
			{
				(*tmp)->next = sec;
				sec->next = fst;
				fst->next = NULL;
				tmp = &(sec->next);
			}
			else
			{
				ListNode* temp = sec;
				res = &temp;
				sec->next = fst;
				fst->next = NULL;
				tmp = &(sec->next);
			}
			if (nextfst)
				fst = nextfst;
			else fst = NULL;
		}
		if (fst && tmp)
			(*tmp)->next = fst;
		if (!res) return head;
		return *res;
	}
};
