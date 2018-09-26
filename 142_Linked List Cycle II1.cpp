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
        ListNode *fp =head, *sp = head;
        while(fp)
        {
          if(fp->next) fp = fp->next->next;
          else break;
            
          sp = sp->next;
          
          if(sp == fp)
          {
              fp =  head;
              while(sp != fp)
              {
                  sp = sp->next;
                  fp = fp->next;
              }
              return sp;
          }
        }
        return NULL;
    }
};
