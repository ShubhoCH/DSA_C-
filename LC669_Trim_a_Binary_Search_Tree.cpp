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
//Space: O(N);
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        if(root->val >= low && root->val <= high){
            TreeNode* r = new TreeNode(root->val); 
            if(root->left)
                r->left = trimBST(root->left, low, high);
            if(root->right)
                r->right = trimBST(root->right, low, high);
            return r;
        }
        if(root->val > high)
            return trimBST(root->left, low, high);
        return trimBST(root->right, low, high);
    }
};
