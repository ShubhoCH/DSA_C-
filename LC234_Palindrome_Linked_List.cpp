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
    bool isPalindrome(ListNode* head) {    
        vector<ListNode*> v;
        while(head){                                
            v.push_back(head);
            head=head->next;
        }
        int j=v.size()-1;
        for(int i=0;i<v.size()/2;i++){              
            if(v[i]->val!=v[j]->val)
                return false;
            j--;
        }
        return true;
    }
};
