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
 
 //Time:  O(2N) = O(N);
 //Space: ?;
class Solution {
public:
    bool Valid(TreeNode* temp, double left, double right){
        if(temp == NULL)
            return true;
        if(!(temp->val > left && temp->val < right))
            return false;
        return Valid(temp->left,left,temp->val)&&Valid(temp->right,temp->val,right);
    }
    bool isValidBST(TreeNode* root) {
        double left = -numeric_limits<float>::infinity(), right = numeric_limits<float>::infinity();
        return Valid(root, left, right);
    }
};
