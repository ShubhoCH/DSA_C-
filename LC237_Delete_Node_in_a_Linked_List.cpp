/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Time:  O(N);
//Space: O(1);
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next){
            node->val = node->next->val;
            if(node->next->next)
                node = node->next;
            else
                node->next = NULL;
        }
    }
};
