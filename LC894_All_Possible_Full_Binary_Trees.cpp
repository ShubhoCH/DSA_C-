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
 
//Time:  O(2^N);
//Space: O(N);
class Solution
{
    public:
    vector<TreeNode*> recur(int n, unordered_map<int,vector<TreeNode*>>& allTrees)
    {
        if(allTrees.find(n)==allTrees.end())
        {
            vector<TreeNode*>trees;
            for(int left=1;left<=n-1;left+=2)
            {
                vector<TreeNode*>leftTrees=recur(left,allTrees);
                vector<TreeNode*>rightTrees=recur(n-left-1,allTrees);
                for(auto leftTree:leftTrees)
                {
                    for(auto rightTree:rightTrees)
                    {
                        TreeNode* root=new TreeNode(0);
                        root->left=leftTree;
                        root->right=rightTree;
                        trees.push_back(root);
                    }
                }
            }
            allTrees[n]=trees;
        }
        return allTrees[n];
    }
    vector<TreeNode*> allPossibleFBT(int n)
    {
        unordered_map<int,vector<TreeNode*>>allTrees;
        allTrees[1].push_back(new TreeNode(0));
        recur(n,allTrees);
        return allTrees[n];
    }
};
