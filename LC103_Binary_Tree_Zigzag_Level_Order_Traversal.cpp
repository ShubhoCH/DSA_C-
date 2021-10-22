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
 
//Time:  O(N * M); Where m is the max width of the tree!
//Space: O(M);
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int dir = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                temp.push_back(q.front()->val);
                if(q.front()->left != NULL)
                    q.push(q.front()->left);
                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
            }
            if(dir==1)
                reverse(temp.begin(),temp.end());
            dir = (dir+1)%2;
            ans.push_back(temp);
        }
        return ans;
    }
};
