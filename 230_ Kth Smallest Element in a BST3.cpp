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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int cnt =  calnode(root->left);
        if(cnt+1 == k) return root->val;
        else if(cnt+1 < k) return kthSmallest(root->right,k - cnt -1);
        else return kthSmallest(root->left,k);
        
    }
    int calnode(TreeNode* root)
    {
        if(!root) return 0;
        return calnode(root->left) + calnode(root->right) +1;
    }
};
