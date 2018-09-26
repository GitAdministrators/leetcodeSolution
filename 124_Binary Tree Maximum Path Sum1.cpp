/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        help(root,res);
        return res;
        
    }
    int help(TreeNode* root , int & res)
    {
        if(!root) return 0;
        int l = max(0,help(root->left,res));
        int r = max(0,help(root->right,res));
        res = max(res,root->val+l+r);
        return root->val+max(l,r);
    }
};
