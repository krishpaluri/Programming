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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       return addTwoNumbers(l1,l2,0);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry) {

        if(l1 == NULL && l2 == NULL && carry == 0)
        {
            return l1;
        }
        int l1val = l1 != NULL ? l1->val : 0;
        int l2val = l2 != NULL ? l2->val : 0;
        ListNode *ans = new ListNode((carry + l1val + l2val) % 10);
        carry = (carry + l1val + l2val) > 9 ? 1 : 0;
        ans->next = addTwoNumbers(l1!=NULL?l1->next:NULL,l2!=NULL?l2->next:NULL,carry);
        return ans;
    }
};
