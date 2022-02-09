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
    unordered_map<int,int> map;
    void helper(TreeNode* curr, int& target, int sum, int& ans)
    {
        if(!curr)
            return;
        sum+=curr->val;
        if(map.find(sum-target)!=map.end())
            ans+=map[sum-target];
        map[sum]++;
        helper(curr->left, target, sum, ans);
        helper(curr->right, target, sum, ans);
        map[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        int ans = 0;
        map[0]++;
        helper(root, targetSum, 0 , ans);
        return ans;
    }
};
