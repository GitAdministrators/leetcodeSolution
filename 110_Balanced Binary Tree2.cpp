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
        int h =0;
        return isBalancedheight(root,h);
    }
    bool isBalancedheight(TreeNode* root , int& h)
    {
        if(root == NULL) return true;
        
        int ld = h;
        if(!isBalancedheight(root->left,ld)) return false;
        
        int rd = h;
        if(!isBalancedheight(root->right,rd)) return false;
        
        h = ld>rd?ld+1:rd+1;
        return abs(ld-rd)<2;
    }
};
