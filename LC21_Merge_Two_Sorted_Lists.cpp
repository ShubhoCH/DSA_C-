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
    ListNode* Merge(ListNode* l1, ListNode* l2, ListNode* temp) {
        if(l1 ==NULL && l2 == NULL)
            return NULL;
        if(l1==NULL){
            temp = l2;
            temp->next = Merge(l1,l2->next,temp->next);
            return temp;
        }else if(l2 == NULL){
            temp = l1;
            temp->next = Merge(l1->next,l2,temp->next);
            return temp;
        }else if(l1->val < l2->val){
            temp = l1;
            temp->next = Merge(l1->next,l2,temp->next);
            return temp;
        }else{
            temp = l2;
            temp->next = Merge(l1,l2->next,temp->next);
            return temp;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* temp = NULL;
        head = Merge(l1,l2,temp);
        return head;
    }
};
