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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* root = head->next;
        ListNode* prev = head;
        while(root){
            if(root->val == prev->val){
                while(root && root->val==prev->val)
                    root = root->next;
                prev->next=root;
            }
            prev=prev->next;
            if(root)
                root=root->next;
        }
        return head;
    }
};
