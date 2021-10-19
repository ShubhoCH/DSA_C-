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
//Space: O(logN -> N);
class Solution {
public:
    bool Check(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        if(left ==NULL || right == NULL)
            return  false;
        if(left->val != right->val)
            return false;
        return Check(left->left, right->right) && Check(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return Check(root->left,root->right);
    }
};
