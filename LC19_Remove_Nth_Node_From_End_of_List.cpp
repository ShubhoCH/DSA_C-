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
    ListNode* RemoveNode(ListNode* temp, int n, int& count){
        if(temp==NULL){
            return NULL;
        }
        temp->next = RemoveNode(temp->next,n,count);
        count++;
        if(count==n){
            if(temp==NULL)
                return NULL;
            else
                return temp->next;
        }
        return temp;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        head = RemoveNode(head,n,count);
        return head;
    }
};
