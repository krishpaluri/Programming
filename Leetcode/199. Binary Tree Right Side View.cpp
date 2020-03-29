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
    vector<int> rightSideView(TreeNode* root) {
        

        vector<int> ans;
        if(root == NULL)
          return ans;
        unordered_map<TreeNode*, int> level;
        queue<TreeNode*> qu;
        int curlevel =0;
        TreeNode* prev = root;
        qu.push(root);
        level[root] = 0;
        while(!qu.empty())
        {
            TreeNode *temp = qu.front();
            if(level[temp] > curlevel)
            {
                ans.push_back(prev->val);
                curlevel = level[temp]; 
            }
            prev = temp;
            qu.pop();
            if(temp->left)
            {
                qu.push(temp->left);
                level[temp->left] = level[temp] +1;
            }
            if(temp->right)
            {
                qu.push(temp->right);
                level[temp->right] = level[temp] +1;
            }            
        }
        ans.push_back(prev->val);
        return ans;
    }
};