/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//Time:  O(N);
//Space: O(N);
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* iter = head;
        while(iter){
            Node* temp = new Node(iter->val);
            m[iter] = temp;
            iter = iter->next;
        }
        iter = head;
        while(iter){
            m[iter]->next = m[iter->next];
            m[iter]->random = m[iter->random];
            iter = iter->next;
        }
        return m[head];
    }
};
