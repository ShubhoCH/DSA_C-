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
 
//Time: O(N)
class Solution {
public:
    bool hasPath(TreeNode* root,int sum, int s){
        if(root == NULL) return false;
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == s) return true;
        return hasPath(root->left, sum, s) || hasPath(root->right, sum, s);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return hasPath(root, 0, targetSum);
    }
};
