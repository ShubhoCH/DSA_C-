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
//Space: O(N->worst, logN->average);
class Solution {
public:
    int preindex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;

        int end = inorder.size() - 1;
        return  tree(preorder, inorder, start, end);
    }
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if (start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preindex++]);
        int inindex;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == root->val)
            {
                inindex = i;

                break;
            }
        }
        root->left = tree(preorder, inorder, start, inindex - 1);
        root->right = tree(preorder, inorder, inindex + 1, end);

        return root;

    }
};
