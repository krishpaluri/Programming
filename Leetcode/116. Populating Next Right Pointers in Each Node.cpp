/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> qu;
        Node *temp = NULL;
        int i=0,j=0;
        if(root == NULL)
            return root;
        qu.push(root);
        while(!qu.empty())
        {
            i++;
            if(temp)
                temp->next = qu.front();
            temp = qu.front();
            qu.pop();
            if(temp->left)
                qu.push(temp->left);
            if(temp->right)
                qu.push(temp->right);
            if(i == (1<<j))
            {
                i = 0;
                j++;
                temp = NULL;
            }

        }
        return root;
    }
};
