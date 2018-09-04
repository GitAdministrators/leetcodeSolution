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
        ListNode* dummy_first = new ListNode(0);
        ListNode* dummy_second = new ListNode(0);
        ListNode* tmp = dummy_second;
        dummy_first->next = head;
        dummy_second->next =head;
        int count = 0;
        while(dummy_first->next!=NULL)
        {
            count++;
            if(count >= n+1)
            {
              tmp = tmp->next;    
            }
            dummy_first = dummy_first->next;
        }
        
        tmp->next= tmp->next->next;
        return dummy_second->next;
    }
};
