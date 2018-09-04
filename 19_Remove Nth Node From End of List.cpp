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
        ListNode* pNode = head;
        int len = 0;
        if(pNode!=NULL) len++;
        while(pNode->next !=NULL)
        {
            len++;
            pNode = pNode->next;
        }
        int index = len - n;
        if(index == 0)
        {
            head =head->next;
            return head;
        }
        
        ListNode* tmp = head;
        for(int i= 0; i<len ; i++)
        {
            if(i== index-1)
            {
                if(tmp->next != NULL)
                {
                    tmp->next = tmp->next->next;
                    tmp = tmp->next;
                }
                break;
                    
            }
            else
            {
                if(tmp->next !=NULL)
                    tmp = tmp->next;
            }
        }    
        return head;
    }
};
