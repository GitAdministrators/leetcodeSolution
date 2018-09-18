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
        if(!head || !head->next) return head;
        ListNode* pNode = head;
        ListNode* tmp = head->next;
        pNode->next =NULL;
        while(tmp)
        {
            ListNode* next = tmp->next;
            tmp->next = head;
            head = tmp;
            tmp = next;
        }
        return head;
    }
};
