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
    
    int dfs(TreeNode* root, bool& flag) {
        if (flag == false) return -1;
        if (root == NULL) return 0;
        int left = dfs(root->left, flag);
        int right = dfs(root->right, flag);
        if (abs(left - right) > 1) flag = false;
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        bool flag = true;
        dfs(root, flag);
        return flag;
    }
};
