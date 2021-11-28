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
 
//Time:  O(M*N); M -> No. of nodes in Root and  N -> No. of nodes in subRoot;
//Space: O(min(M,N));
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return false;
        if(sameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL) return root == NULL && subRoot == NULL;
        if(root->val == subRoot->val)
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        return false;
    }
};
