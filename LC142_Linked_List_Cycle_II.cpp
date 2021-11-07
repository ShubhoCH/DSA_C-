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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
             return nullptr;
         ListNode* iter = head;
         unordered_set<ListNode*> hmap;
         while(iter){
             if(hmap.find(iter) == hmap.end()){
                 hmap.insert(iter);
                 iter = iter->next;
             }else
                 return iter;
         }
         return nullptr;
    }
};
