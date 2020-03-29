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

    bool helper(TreeNode *A,TreeNode *B)
    {
        if(A == NULL && B == NULL)
            return true;
        if(A == NULL ^ B == NULL)
            return false;
        if(A->val == B->val && helper(A->left,B->right) && helper(A->right,B->left))
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return helper(root->left,root->right);

    }
};
