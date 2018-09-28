/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
       5
      / \
     3   6
    / \
   2   4
  /
 1
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0; 
        dfs(root,k,ans);
        return ans;
    }
    void dfs(TreeNode* root ,int& k,int& ans)
    {
        if(root && root->left)
        {
           dfs(root->left,k,ans);
        }
        k--;
        if(k == 0) ans = root->val;
        if(root && root->right)
        {
            dfs(root->right,k,ans);
        }
    }
};
