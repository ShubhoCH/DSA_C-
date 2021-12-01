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
//Space: O(1);
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return find(root, root, k);
    }
    bool find(TreeNode* root, TreeNode* curr, int k){
        if(curr == NULL) return false;
        if(BS(root, k-curr->val, curr->val))
            return true;
        return find(root, curr->left, k) || find(root, curr->right, k);
    }
    bool BS(TreeNode* root, int v, int curr){
        if(root == NULL) return false;
        if(root->val == v && root->val != curr)
            return true;
        if(root->val>v)
            return BS(root->left, v, curr);
        else
            return BS(root->right, v, curr);
    }
};
