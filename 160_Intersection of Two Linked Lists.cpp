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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while(tmpA)
        {
            ++lenA;
            tmpA = tmpA->next;
        }
        while(tmpB)
        {
            ++lenB;
            tmpB = tmpB->next;
        }
        tmpA = headA;
        tmpB = headB;
        
        if(lenA <lenB)
        {
            int dis = lenB - lenA;
            while(dis>0)
            {
                dis--;
                tmpB= tmpB->next;
            }
            while(tmpA && tmpB)
            {
                if(tmpA == tmpB) return tmpA;
                tmpA = tmpA->next;
                tmpB = tmpB->next;
            }
        }
        else
        {
            int dis = lenA-lenB;
            while(dis>0)
            {
                dis--;
                tmpA=tmpA->next;
            }
            while(tmpA && tmpB)
            {
                if(tmpA == tmpB) return tmpA;
                tmpA =tmpA->next;
                tmpB =tmpB->next;
            }
        }
        return NULL;
    }
};
