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
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        count(root, INT_MIN, ans);
        return  ans;
    }
    void count(TreeNode* root, int curr, int& sum){
        if(!root)
            return;
        if(root->val>=curr){
            sum++;
            curr = root->val;
        }
        count(root->left, curr, sum);
        count(root->right, curr, sum);
    }
};
