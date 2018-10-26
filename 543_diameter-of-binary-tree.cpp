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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int subld = diameterOfBinaryTree(root->left);
        int subrd = diameterOfBinaryTree(root->right);
        int ld = geth(root->left);
        int rd = geth(root->right);
        int tmp1 = max(subld,subrd);
        int tmp2 = ld+rd;
        return max(tmp1,tmp2);
    }
    
    int geth(TreeNode* root)
    {
        if(!root) return 0;
        int ld = geth(root->left);
        int rd = geth(root->right);
        return ld>rd?ld+1:rd+1;
    }
};
