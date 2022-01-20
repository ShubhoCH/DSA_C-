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
 
//Time:  O(N+M);
//Space: O(1);
class Solution {
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        bool left = true, right = true;
        if(r1->val != r2->val) return false;
        left = flipEquiv(r1->left, r2->left) || flipEquiv(r1->left, r2->right);
        right = flipEquiv(r1->right, r2->left) || flipEquiv(r1->right, r2->right);
        return left && right;
    }
};
