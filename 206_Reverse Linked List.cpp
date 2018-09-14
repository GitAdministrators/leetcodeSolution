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
        if(!head ||!head->next) return head;
        ListNode* pNode = head;
        ListNode* fst = head;  
        ListNode* sec = fst->next;     
        ListNode* tmp = NULL;
        fst->next =NULL;
        while(sec)
        {
            if(sec->next)  
            {
                tmp = sec; 
                sec =sec->next;    
                tmp->next = fst; 
                fst = tmp;
                head= fst;
            }
            else
            {
                head = sec;
                sec->next = fst;
                break;
            }
        }
        return head;
    }
};
