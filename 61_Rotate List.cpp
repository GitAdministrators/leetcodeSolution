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
        if(k == 0 || !head) return head;
        ListNode* slow = head; 
        ListNode* fast = head;
        int count = 0;
        while(k)
        {
            if(count>=0)
            {
                count++;
                fast = fast->next;
                if(!fast) 
                {
                    fast = head;
                    k = k%count ;
                    count = -1;
                 }
            }
            else
            {
                fast = fast->next;
                if(!fast) fast =head;
                k--;
            }
        }
        while(true)
        {
            if(!fast->next) break;
            fast = fast->next;
            slow = slow->next;
            if(!slow) slow = head;
        }
        ListNode* tmp = slow->next;
        if(!tmp) tmp = head;
        fast->next = head;
        slow->next = NULL;
        head = tmp;
        return head;
    }
};
