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
//Space: O(1);
class data{
public:
    int with;
    int without;
    data(){
        with = without = 0;
    }
};
class Solution: public data {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        data d = Rob(root,data());
        return max(d.with, d.without);
    }
    data Rob(TreeNode* root, data d){
        if(root == NULL) return d;
        data left = Rob(root->left, d);
        data right = Rob(root->right, d);
        d.with = root->val + left.without + right.without;
        d.without = max(left.without, left.with) + max(right.without, right.with);
        return d;
    }
};
