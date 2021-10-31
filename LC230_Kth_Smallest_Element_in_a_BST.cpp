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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        smallest(root, k, ans);
        return ans;
    }
    void smallest(TreeNode* root, int& k, int& ans){
        if(!root) return;
        smallest(root->left, k, ans);
        k--;
        if(k == 0){ 
            ans = root->val;
            return;
        }
        smallest(root->right, k, ans);
    }
};
