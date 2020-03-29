/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *ans = NULL;
    void helper(ListNode *headA, ListNode *headB)
    {


    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> st1,st2;

        while(headA)
        {
            st1.push(headA);
            headA = headA->next;
        }
        while(headB)
        {
            st2.push(headB);
            headB = headB->next;
        }
        ListNode *ans = NULL;
        while(!st1.empty() and !st2.empty())
        {
            if(st1.top() != st2.top())
            {

                return ans;
            }
            ans = st1.top();
            st1.pop();
            st2.pop();
        }

        return ans;

    }
};
