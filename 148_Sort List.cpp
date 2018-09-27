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
        vector<int> vec;
        ListNode* pnode = head;
        while(pnode)
        {
            vec.push_back(pnode->val);
            pnode = pnode->next;
        }
        sort(vec.begin(),vec.end());
        ListNode* p = new ListNode(0);
        ListNode* tmp = p;
        for(int i = 0 ; i< vec.size();i++)
        {
            ListNode* t = new ListNode(vec[i]);
            tmp->next = t;
            tmp= tmp->next;
        }
        return p->next;
    }
};
