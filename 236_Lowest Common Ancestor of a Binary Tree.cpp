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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(findsub(p,q)) return p;
        if(findsub(q,p)) return q;
        
        while(true)
        { 
            TreeNode* tmproot = findup(root,p); 
            if(findsub(tmproot,q)) return tmproot;
            p = tmproot;
        }
        return root;
    }
    bool findsub(TreeNode* root, TreeNode* sub)
    {
        if(!root) return false;
        if(root == sub) return true;
        return findsub(root->left,sub) || findsub(root->right,sub);
    }
    TreeNode* findup(TreeNode* root,TreeNode* sub)
    {
        if(!root) return NULL;
        if(root->left == sub || root->right == sub) return root;
        TreeNode* tmp = findup(root->left,sub);
        if(tmp) return tmp;
        return findup(root->right,sub);
    }
};
