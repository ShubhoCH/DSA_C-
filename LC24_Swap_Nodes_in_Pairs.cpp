/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* l;
        ListNode* r;
        l=head;
        if(l->next)
            r = l->next;
        while(l&&r){
            int temp = l->val;
            l->val=r->val;
            r->val = temp;
            l=r->next;
            if(l)
                r=l->next;
        }
        return head;
    }
};
