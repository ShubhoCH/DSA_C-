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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        find(root, ans);
        return ans;
    }
    int find(TreeNode* root, int& ans){
        if(!root) return 0;
        int left = find(root->left, ans);
        int right = find(root->right, ans);
        if(left+right>ans) ans = left + right;
        return max(left, right) + 1;
    }
};
