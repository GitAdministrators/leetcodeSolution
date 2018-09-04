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
        ListNode*  pNode = new ListNode(0);
        ListNode* tmp = pNode;
        pNode->next =  head;
        int len = 0;
        while(tmp->next !=NULL)
        {
            len++;
            tmp = tmp->next;
        }
        int index = len - n;
        tmp = pNode;
        for(int i= 0; i<index ; i++)
        {
            tmp = tmp->next;
        }    
        if(tmp->next!=NULL)
            tmp->next = tmp->next->next;
        return pNode->next;
    }
};
