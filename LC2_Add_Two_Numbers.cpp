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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        int carry = 0;
        ListNode* head = ans;
        while(true){
            if(!(l1 == NULL)){
                carry += l1->val;
                l1=l1->next;
            }
            if(!(l2 == NULL)){
                carry += l2->val;
                l2=l2->next;
            }
            ListNode* newNode = new ListNode(carry%10);
            newNode->next = NULL;
            head->next = newNode;
            head = head->next;
            carry /= 10;
            
            if(l1==NULL && l2==NULL){
                if(carry!=0)
                {
                    ListNode* newNodeEnd = new ListNode(carry%10);
                    newNodeEnd->next = NULL;
                    head->next = newNodeEnd;
                }
                break;
            }
        }
        return ans->next;
    };
};
