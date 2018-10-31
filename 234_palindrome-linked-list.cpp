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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* pNode = head;
        while(pNode)
        {
            pNode = pNode->next;
            len++;
        }
        if(len == 0 || len ==1) return true;
        ListNode* fast =head;
        ListNode* p = NULL;
        for(int i =0 ; i<len/2;i++)
        {
            ListNode* tmp = fast->next;
            fast->next = p;
            p = fast;
            fast = tmp;
        }
        ListNode* slow = p ;
        if(len%2 == 1 ) fast=fast->next;
        while(fast)
        {
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
