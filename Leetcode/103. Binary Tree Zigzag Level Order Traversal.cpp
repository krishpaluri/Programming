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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> st1,st2;
        int flag = 1;

        st1.push(root);
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> ans_row;
        while(!st1.empty() || !st2.empty())
        {
            TreeNode *temp = NULL;
            if(flag == 1)
            {
                temp = st1.top();
                st1.pop();
                ans_row.push_back(temp->val);
                if(st1.empty())
                {
                    flag ^=1;
                    ans.push_back(ans_row);
                    ans_row.clear();
                }
                if(temp->left)
                    st2.push(temp->left);
                if(temp->right)
                    st2.push(temp->right);
            }
            else
            {
                temp = st2.top();
                if(temp->right)
                    st1.push(temp->right);
                if(temp->left)
                    st1.push(temp->left);
                st2.pop();
                ans_row.push_back(temp->val);
                if(st2.empty())
                {
                    flag ^=1;
                    ans.push_back(ans_row);
                    ans_row.clear();
                }
            }

        }
        return ans;
    }
};
