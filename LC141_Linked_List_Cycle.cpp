//Time:  O(N);
//Space: O(1);
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }return false;   
    }
};
