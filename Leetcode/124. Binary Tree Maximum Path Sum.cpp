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

    int helper(TreeNode *root,int &maxpath)
    {
        if(root == NULL)
            return 0;

        int lc = helper(root->left,maxpath);
        int rc = helper(root->right,maxpath);
        int maxc = root->val + (lc>rc?lc:rc);

        // If root is bigger then adding other would be at loss
        if(maxc <= root->val)
            maxc = root->val;
        // lets assign maxpath for this node
        if(maxpath <= maxc)
            maxpath = maxc;
        // lets include even root to see if its global maximum
        if(maxpath <= (root->val + lc + rc))
            maxpath = (root->val + lc + rc);
        //return only maxc for other to use maxpath from this node
        return maxc;
    }
    int maxPathSum(TreeNode* root) {

        int maxpath =INT_MIN;
        helper(root,maxpath);
        return maxpath;

    }
};
