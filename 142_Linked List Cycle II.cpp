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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> pmap;
        ListNode* cur = head;
        while(cur)
        {
            if(pmap.find(cur)!=pmap.end())
            {
                return cur;
            }
            pmap[cur] =true;
            cur = cur->next;
        }
        return NULL;        
    }
};
