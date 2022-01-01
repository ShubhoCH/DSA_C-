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

//Time:  O(N);
//Space: O(1); 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *temp1 = NULL;
        ListNode *temp2 = head;
        while(temp2){
            ListNode *temp = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp;
        }
        return temp1;
    }
};
