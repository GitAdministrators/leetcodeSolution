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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        int len = 0;
        ListNode* pnode = head;
        while(pnode)
        {
            ++len;
            pnode = pnode->next;
        }
        ListNode* left = head;
        ListNode* right = splitlist(head,len/2);
        left  = sortList(left);
        right = sortList(right);
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(left && right)
        {
            if(left->val <right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        
        if(left)
        {
            cur->next =left;
        }
        else if(right)
        {
            cur->next = right;
        }
        
        return dummy->next;
    }
    
    ListNode* splitlist(ListNode* head,int len)
    {
        if(!head) return head;
        for(int i = 1 ; i<len;i++)
        {
            head =head->next;
        }
        ListNode* tmp = head->next;
        head->next = NULL;
        return tmp;
    }
};
