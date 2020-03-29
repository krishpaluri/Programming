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
TreeNode *pre=NULL,*first=NULL, *last = NULL;
void inOrder(TreeNode *A)
{
    if(A == NULL)
       return;
    inOrder(A->left);
    if(pre != NULL && A->val < (pre)->val)
    {
        if(first == NULL)
        {
            first = pre;
        }
        last = A;
    }
    pre = A;
    inOrder(A->right);
}

  void recoverTree(TreeNode* A) {
    inOrder(A);
    int temp = first->val;
    first->val = last->val;
    last->val = temp;
}
};
