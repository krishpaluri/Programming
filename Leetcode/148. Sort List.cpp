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

ListNode* merge(ListNode* left,ListNode* right){
        if(!left) return right;
        if(!right) return left;
        if(left->val<=right->val){
            left->next=merge(left->next,right);
            return left;
        }
        else{
            right->next=merge(right->next,left);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(mid));
    }

};
