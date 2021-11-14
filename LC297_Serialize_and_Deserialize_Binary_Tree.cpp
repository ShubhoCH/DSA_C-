/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Time:  O(N);
//Space: O(N);
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "N";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int s = data.length();
        queue<string> q;
        for(int i=0;i<s;i++){
            string ss = "";
            while(i<s && data[i] != ',') ss+=data[i++];
            q.push(ss);
        }
        return d(q);
    }
    TreeNode* d(queue<string>& q){
        if(q.empty()) return NULL;
        string peek = q.front();
        q.pop();
        if(peek == "N") return NULL;
        int val = stoi(peek);
        TreeNode* root = new TreeNode(val);
        root->left = d(q);
        root->right = d(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
