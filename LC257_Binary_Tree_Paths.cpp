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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        Paths(root, ans, s);
        return ans;
    }
    void Paths(TreeNode* root, vector<string>& ans, string s){
        if(root == NULL)
            return;
        s += to_string(root->val);
        if(root->left != NULL || root->right != NULL) s+= "->";
        else{
            ans.push_back(s);
            return;
        }
        Paths(root->left, ans, s);
        Paths(root->right, ans, s);
    }
};
