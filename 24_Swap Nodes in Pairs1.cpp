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
        if(!head || head->next ==NULL) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        head = head->next;
        ListNode* pre =NULL;
        while(right)
        {
            if(pre) pre->next = right;
            left->next = right->next;
            right->next = left;
            pre = left;
            left = left->next;
            if(left)
                right = left->next;
            else
                break;
        }
        return head;
    }
};
