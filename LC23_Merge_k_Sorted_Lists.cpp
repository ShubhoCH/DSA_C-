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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;
        ListNode* head = NULL;
        for(ListNode* x: lists){
            while(x){
                pq.push(x->val);
                x=x->next;
            }
        }
        while(!pq.empty())
        {
            ListNode* temp = new ListNode();
            temp->val = pq.top();
            temp->next = head;
            head = temp;
            pq.pop();
        }
        return head;
    }
};

