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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode * oddHead = head;
        ListNode * evenHead = head->next;

        ListNode *oddP = oddHead;
        ListNode *evenP = evenHead;

        while(oddP != NULL and evenP != NULL)
        {
            oddP->next = evenP->next;


            // in case of even length of linkedlist
            // we cant afford to lose last pointer of odd linkedlist
            // if we lose we need to traverse gain to last
            // in case of odd length even will be null first.
            if(oddP->next == NULL)
            {
                cout<<"here";
                evenP->next = NULL;
                break;
            }
            oddP = oddP->next;
            evenP->next = oddP->next;
            evenP = evenP->next;
        }
        oddP->next = evenHead;
        return oddHead;

    }
};
