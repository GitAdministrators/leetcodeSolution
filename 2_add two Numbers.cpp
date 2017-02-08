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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = NULL;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        int l1_val;
        int l2_val;
        int sum;
        int need_add = 0;
        while(l1 !=NULL || l2 !=NULL || need_add !=0)
        {
            l1_val = (l1!=NULL)? l1->val : 0;
            l2_val = (l2!=NULL)? l2->val : 0;
            sum = l1_val + l2_val + need_add;
            if (sum > 9)
            {
                 temp = new ListNode(sum - 10);
                 need_add = 1;
            }
            else
            {
                 temp = new ListNode(sum);
                 need_add = 0;
            }
            
            l1 = (l1!=NULL)?l1->next:l1;
            l2 = (l2!=NULL)?l2->next:l2;
            if(!head)
            {
                head = temp;
            }
            if(prev)
            {
                prev->next = temp;
                prev = prev->next;
            }
            else
            {
                prev = temp;
            }
        }
        return head;
    }
};
