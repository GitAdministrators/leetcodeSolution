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
        ListNode* dummy = new ListNode(0);
        ListNode* first = dummy;
        while(l1 !=NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                dummy->next = l2;
                l2 = l2->next;
            }
            else if(l2 == NULL)
            {
                dummy->next = l1;
                l1 =l1->next;
            }
            else if(l1->val > l2->val)
            {
                dummy->next = l2;
                l2= l2->next;
            }
            else 
            {
                dummy->next = l1;
                l1 =l1->next;
            }
            dummy = dummy->next;
        }
        return first->next;
    }
};
