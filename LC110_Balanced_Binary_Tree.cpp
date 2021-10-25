/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
//Time:  O(N);
//Space: O(N: worst <-> logN: average);
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(Check(root) == -1)
            return false;
        return true;
    }
    int Check(TreeNode* temp){
        if(temp == NULL)
            return 0;
        int left = Check(temp->left);
        if(left == -1)
            return -1;
        int right = Check(temp->right);
        if(right == -1)
            return -1;
        if(abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
