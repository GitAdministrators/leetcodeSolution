/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp
{
    bool operator() (const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp > qp;
        int len = lists.size();
        ListNode* pNode = new ListNode(0);
        ListNode* tmp = pNode;
        for(auto i : lists)
        {
            if(i) qp.push(i); 
        }
        
        while(!qp.empty())
        {
            tmp->next = qp.top();
            tmp = tmp->next;
            qp.pop();
            if(tmp->next) qp.push(tmp->next);
        }
        
        ListNode* res = pNode;
        res = res->next;
        delete pNode;
        return res;
    }
};
