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
 
//Time: O(1 - N);
class BSTIterator {
public:
    queue<TreeNode*> q;
    void inOrder(TreeNode* root) {
        if(root == nullptr) return;
        inOrder(root->left);
        q.push(root);
        inOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    int next() {
        int value = q.front()->val;
        q.pop();
        return value;
    }
    bool hasNext() {
        if(q.size()>0) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
