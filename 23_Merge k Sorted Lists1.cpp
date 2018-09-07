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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size()>1)
        {
            ListNode* first = lists[0];
            ListNode* second= lists[1];
            ListNode* merge = new ListNode(0);
            ListNode* tmp = merge;
            while(first!=NULL || second!=NULL)
            {
                if(first ==NULL)
                {
                    merge->next = second;
                    second = second->next;
                    merge= merge->next;
                    break;
                }
                else if(second == NULL)
                {
                    merge->next = first;
                    first= first->next;
                    merge = merge->next;
                    break;
                }
                else
                {
                    if(first->val >= second->val)
                    {
                        merge->next = second;
                        second = second->next;
                        merge= merge->next;
                    }
                    else
                    {
                        merge->next = first;
                        first= first->next;
                        merge = merge->next;
                    }
                }
            }
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(tmp->next);
        }
        return lists.front();
    }
};
