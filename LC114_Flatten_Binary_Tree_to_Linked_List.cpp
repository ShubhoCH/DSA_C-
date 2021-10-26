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
//Space: O(N);
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* newNode = s.top();
            s.pop();
            if(newNode->right!=NULL)
                s.push(newNode->right);
            if(newNode->left!=NULL)
                s.push(newNode->left);
            if(!s.empty())
                newNode->right = s.top();
            newNode->left = NULL;
        }
    }
};
