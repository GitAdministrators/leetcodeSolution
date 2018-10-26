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
    bool isBalanced(TreeNode* root) {
       if(root == NULL)
            return true;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        int distance = leftDepth - rightDepth;

        if(distance > 1 || distance < -1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode* root)
    {
        if(root ==NULL) return 0;
        int ld = depth(root->left);
        int rd = depth(root->right);
        return max(ld,rd)+1;
    }
};
