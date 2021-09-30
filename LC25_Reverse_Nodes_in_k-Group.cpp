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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* arr[k];
        ListNode* temp = head;
        int i=0;
        while(temp){
            arr[i] = temp;
            i++;
            temp = temp->next;
            if(i==k){
                int j=0,l=k-1;
                while(j<l){
                    int temp2 = arr[j]->val;
                    arr[j]->val = arr[l]->val;
                    arr[l]->val = temp2;
                    j++;
                    l--;
                }
                i=0;
            }
        }
        return head;
    }
};
