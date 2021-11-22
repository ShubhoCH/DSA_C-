//Time:  O(N);
//Space: O(N);
class trieNode{
public:
    trieNode* left;
    trieNode* right;
};
class Solution {
public:
    void insert(trieNode* head, int n){
        trieNode* curr=head;
        for(int j=31;j>=0;j--){
            int bit=(n>>j)&1;
            if(bit==0){
                if(!curr->left){
                    curr->left=new trieNode();
                }
                curr=curr->left;
            }
            else{
                if(!curr->right){
                    curr->right=new trieNode();
                }
                curr=curr->right;
            }
        }
    }
    int helper(trieNode* head,vector<int>&nums){
        int max_xor=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int value=nums[i];
            trieNode*curr=head;
            int curr_xor=0;
            for(int j=31;j>=0;j--){
                int bit=(value>>j)&1;
                if(bit==0){
                    if(curr->right){
                        curr_xor+=pow(2,j);
                        curr=curr->right;
                    }
                    else{
                        curr=curr->left;
                    }
                }
                else{
                    if(curr->left){
                        curr_xor+=pow(2,j);
                        curr=curr->left;
                    }
                    else{
                        curr=curr->right;
                    }
                }
                
            }
            if(curr_xor>max_xor){
                max_xor=curr_xor;
            }
        }
        return max_xor;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* head=new trieNode();
        for(auto num :nums){
            insert(head,num);
        }
        return helper(head,nums);
    }
};
