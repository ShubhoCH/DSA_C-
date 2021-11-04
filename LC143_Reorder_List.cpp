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
//Space: O(N);
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp = head;
        int size = 0;
        while(temp){
            v.push_back(temp);
            temp=temp->next;
            size++;
        }
        int l=0,r=size-1;
        for(;l<r;){
            v[l++]->next = v[r];
            if(l<r)
                v[r--]->next = v[l];
        }
        if(size%2==0)
            v[l]->next = NULL;
        else
            v[r]->next = NULL;
        head = v[0];
    }
};
