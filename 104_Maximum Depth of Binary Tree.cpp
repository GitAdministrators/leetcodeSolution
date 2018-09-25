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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int max =0;
        int cur =1;
        dfs(root,max,cur);
        return max;
    }
private:
    void dfs(TreeNode* root , int& max,int cur)
    {
        if(!root->left && !root->right)
        {
            max  =max>cur?max:cur;
            return;
        }
        if(root->left)
        {
            dfs(root->left,max,cur+1);
        }
        if(root->right)
        {
            dfs(root->right,max,cur+1);
        }
    }
};
