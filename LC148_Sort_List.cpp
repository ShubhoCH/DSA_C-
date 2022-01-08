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
 
//Time:  O(N*LogN);
//Space: O(logN);
class Solution {
public:
    void MergeSort(ListNode** head){
        ListNode* curr = *head;
        ListNode* first;
        ListNode* second;
        if(!curr or !curr->next) return;
        FindMiddle(curr, &first, &second);
        
        MergeSort(&first);
        MergeSort(&second);
        *head = MergeBoth(first, second);
    }
    ListNode* MergeBoth(ListNode* first, ListNode* second){
        ListNode* ans = NULL;
        if(!first) return second;
        if(!second) return first;
        if(first->val <= second->val){
            ans = first;
            ans->next = MergeBoth(first->next, second);
        }else{
            ans = second;
            ans->next = MergeBoth(first, second->next);
        }
        return ans;
    }
    void FindMiddle(ListNode* curr, ListNode** first, ListNode** second){
        ListNode* fast;
        ListNode* slow;
        slow = curr;
        fast = curr->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        *first = curr;
        *second = slow->next;
        slow->next = NULL;
    }
    ListNode* sortList(ListNode* head) {
        MergeSort(&head);
        return head;
    }
};
