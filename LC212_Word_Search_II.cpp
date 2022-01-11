//Time:  O(NM *NM);
//Space: O(N);
class Solution {
    struct Node {
        char c;
        int ends;
        string word;
        Node* child[26];
    }; 
    struct Node *getNode(char c){
        Node* newNode = new Node();
        newNode->c = c;
        newNode->ends = 0;
        newNode->word = "";
        for(int i=0;i<26;i++)
            newNode->child[i] = NULL;
        return newNode;
    }
    Node *root = getNode('/');
    void insert(string s){
        Node *curr=root;
        int index, i = 0;
        while(s[i]){
            index = s[i]-'a';
            if(curr->child[index] == NULL)
                curr->child[index] = getNode(s[i]);
            curr = curr->child[index];
            i+=1;
        }
        curr->ends+=1;
        curr->word = s;
    }
public:
    void solve(vector<vector<char>>& board, int i, int j, int r, int c, vector<string>& ans, Node *curr){
        int index = board[i][j] - 'a';
        if(board[i][j] == '$' || curr->child[index] == NULL)
            return ;
        curr = curr->child[index];
        if(curr->ends > 0){
            ans.push_back(curr->word);
            curr->ends -= 1;
        }
        char ch = board[i][j];
        board[i][j] = '$';
        if(i>0)
            solve(board,i-1,j,r,c,ans, curr);
        if(i<r-1)
            solve(board,i+1,j,r,c,ans, curr);
        if(j>0)
            solve(board,i,j-1,r,c,ans, curr);
        if(j<c-1)
            solve(board,i,j+1,r,c,ans, curr);
        board[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        int r=b.size();
        int c=b[0].size();
        for(int i=0;i<words.size();i++)
            insert(words[i]);
        vector<string> ans;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                solve(b,i,j,r,c,ans,root);
            }
        return ans;
    }
};
