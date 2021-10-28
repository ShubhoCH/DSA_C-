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
//Space: Only for Stack;
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
    int sum(TreeNode* root, int s){
        s = s*10 + root->val;
        if(root->left==NULL && root->right==NULL) return s;
        int left = 0, right = 0;
        if(root->left)
            left = sum(root->left, s);
        if(root->right)
            right = sum(root->right, s);
        return left + right;
    }
};
