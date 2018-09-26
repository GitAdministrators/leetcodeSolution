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
    bool hasCycle(ListNode *head) {
        ListNode* fast =head, *slow = head;
        bool bslow = true;
        while(fast)
        {
            fast = fast->next;
            if(!bslow) slow=slow->next;
            bslow = !bslow;
            if(slow == fast)return true;
        }
        return false;
    }
};
