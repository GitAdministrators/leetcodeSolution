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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0) return head;
        ListNode* newhead=head,*tail=head;
        int len = 0;
        while(tail)
        {
            len++;
            if(!tail->next) break;
            tail=tail->next;
        }
        tail->next = head;
        if(k%=len)
        {
            for(int i = 0;i<len-k;i++)
            {
                tail= tail->next;
            }
        }
        newhead = tail->next;
        tail->next =NULL;
        return newhead;
    }
};
