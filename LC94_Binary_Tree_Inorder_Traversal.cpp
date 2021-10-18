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
    void Inorder(vector<int>& ans, TreeNode* temp){
        if(temp==NULL)
            return;
        Inorder(ans, temp->left);
        ans.push_back(temp->val);
        Inorder(ans, temp->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Inorder(ans, root);
        return ans;
    }
};
