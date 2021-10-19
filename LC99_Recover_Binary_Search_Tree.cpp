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
 //Space: O(logN); for recurssion stack;
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* previous = new TreeNode(INT_MIN);
    void Inorder(TreeNode* temp){
        if(temp == NULL) return;
        Inorder(temp->left);
        if(first == NULL && previous->val > temp->val)
            first = previous;
        if(first != NULL && previous->val > temp->val){
            second = temp;
        }
        previous = temp;
        Inorder(temp->right);
    }
    void recoverTree(TreeNode* root) {
        Inorder(root);
        int v = first->val;
        first->val = second->val;
        second->val = v;
    }
};
