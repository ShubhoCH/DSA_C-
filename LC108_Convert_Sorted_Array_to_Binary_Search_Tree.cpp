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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return Create(nums, 0, nums.size() - 1);
    }
    TreeNode* Create(vector<int> nums, int start, int end){
        if(start>end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = Create(nums, start, mid-1);
        temp->right = Create(nums, mid+1, end);
        return temp;
    }
};
