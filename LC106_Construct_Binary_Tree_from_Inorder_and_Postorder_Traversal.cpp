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
//Space: O(logN : Average <-> N : Worst);
class Solution {
public:
    int preindex  = 0 ;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int end = inorder.size() - 1;
        return  tree(postorder, inorder, 0, end);
    }
    TreeNode* tree(vector<int>& postorder, vector<int>& inorder, int start, int end)
    {
        if (start > end)
            return NULL;
        TreeNode* root = new TreeNode(postorder[inorder.size() - 1 - preindex++]);
        int inindex;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == root->val)
            {
                inindex = i;
                break;
            }
        }
        root->right = tree(postorder, inorder, inindex + 1, end);
        root->left = tree(postorder, inorder, start, inindex - 1);
        return root;
    }
};
