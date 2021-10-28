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
//Space: O(N->lonN);
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxx = INT_MIN;
        maxPath(root, maxx);
        return maxx;
    }
    int maxPath(TreeNode* root, int& maxx){
        if(root==NULL) return 0;
        int left = max(0, maxPath(root->left, maxx));
        int right = max(0, maxPath(root->right, maxx));
        maxx = max(maxx, left + right + root->val);
        return max(left, right) + root->val;
    }
};
