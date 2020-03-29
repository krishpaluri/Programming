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
    vector<int> postorderTraversal(TreeNode* A) {
            stack<TreeNode *> st;
    vector<int> res;
    if(A == NULL)
       return res;

    unordered_map<TreeNode *,bool> umap;
    st.push(A);
    while(!st.empty())
    {
        TreeNode *temp = st.top();
        if((temp->right != NULL) and (umap.find(temp->right) == umap.end()))
           st.push(temp->right);
        if((temp->left != NULL) and (umap.find(temp->left) == umap.end()))
           st.push(temp->left);
        if(temp->left == NULL && temp->right == NULL)
        {
            cout<<"here";
            umap[temp] = true;
            cout<<temp->val<<" ";
            res.push_back(temp->val);
            st.pop();
        }
        else if((temp->left == NULL || umap.find(temp->left) != umap.end()) and (temp->right== NULL || umap.find(temp->right) != umap.end()))
        {
            umap[temp] = true;
            cout<<temp->val<<" ";
            res.push_back(temp->val);
            st.pop();
        }
    }
        return res;
    }
};
