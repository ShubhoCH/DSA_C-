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
//Time: O(N);
//Space: O(2N) for stack and temp vector i.e. O(N);
class Solution {
public:
    void findPath(TreeNode* root, vector<vector<int>>& ans, vector<int> temp, int s, int sum){
        if(root == NULL) return;
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == s){
            ans.push_back(temp);
            return;
        }
        findPath(root->left, ans, temp, s, sum);
        findPath(root->right, ans, temp, s, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans; 
        vector<int> temp;
        findPath(root, ans, temp, targetSum, 0);
        return ans;
    }
};
