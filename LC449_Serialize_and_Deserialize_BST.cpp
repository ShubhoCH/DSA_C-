/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Time:  O(NlogN);
//Space: O(logN);
class Codec {
public:
   string serialize(TreeNode *root) {
      string ret = "";
      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty()) {
         TreeNode *curr = q.front();
         q.pop();
         if (!curr) {
            ret += "N";
            ret += " ";
            continue;
         }
         ret += to_string(curr->val);
         ret += " ";
         q.push(curr->left);
         q.push(curr->right);
      }
      return ret;
   }
   TreeNode *deserialize(string data) {
      if (data[0] == 'N')
         return NULL;
      string temp = "";
      vector<string> v;
      for (int i = 0; i < data.size(); i++) {
         if (data[i] == ' ') {
            v.push_back(temp);
            temp = "";
            continue;
         }
         temp += data[i];
      }
      TreeNode *newRoot = new TreeNode(stoi(v[0]));
      queue<TreeNode *> q;
      q.push(newRoot);
      int i = 1;
      while (!q.empty() && i < v.size()) {
         TreeNode *parent = q.front();
         q.pop();
         if (v[i] != "N") {
            parent->left = new TreeNode(stoi(v[i]));
            q.push(parent->left);
         }
         i++;
         if (v[i] != "N") {
            parent->right = new TreeNode(stoi(v[i]));
            q.push(parent->right);
         }
         i++;
      }
      return newRoot;
   }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
