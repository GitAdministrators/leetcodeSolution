/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListPreNode
{
    int val;
    ListPreNode* pre;
    ListPreNode(int x):val(x),pre(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !(head->next) || k == 1) return head;
        std::vector<ListNode*> vec;
        ListNode* cur = head;
        ListNode* newhead = NULL;
        ListNode* point =NULL;
        ListNode* pre = NULL;
        bool hasK = true;
        while(1)
        {
            for(int i = 0;i<k;i++)
            {
                if(cur) vec.push_back(cur);
                else {hasK= false; break;}
                point = cur;
                cur = cur->next;
            }            
            if(!hasK) break;
            if(!newhead) newhead = point;
            if(pre) pre->next = point;
            ListNode* next = cur;
            
            while(!vec.empty())
            {
                point->next =  vec.back();
                point = point->next;
                vec.pop_back();
            }
            point->next = cur;   
            pre = point;
        }
        if(newhead) return newhead;
        return head;
    }
};
