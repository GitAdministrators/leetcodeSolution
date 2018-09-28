class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       int cnt =  0; 
       stack<TreeNode*> stk;
       TreeNode* p = root;
       while(p||!stk.empty())
       {
           while(p)
           {
               stk.push(p);
               p=p->left;
           }
           p =stk.top();
           stk.pop();
           ++cnt;
           if(cnt == k) return p->val;
           p=p->right;
       }
       return 0;
    }
};
