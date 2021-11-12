//Time:  O(N*M);
//Space: O(N*M);
class Solution {
public:
    int l1, l2;
    int minDistance(string word1, string word2) {
        int ans = 0;
        vector<vector<int>> dp(word1.length() + 1,vector<int>(word2.length() + 1, -1));
        l1 = word1.length();
        l2 = word2.length();
        ans = count(word1, word2, dp);
        return ans;
    }
    int count(string s1, string s2, vector<vector<int>>& dp){
        if(s1 == "" && s2 == "") return 0;
        if(s1 == "" || s2 == "") return (s1=="")?s2.length():s1.length();
        int i, j;
        i = l1 - s1.length();
        j = l2 - s2.length();
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[0] == s2[0])
            return dp[i][j] = count(s1.substr(1),s2.substr(1), dp);
        else{
            int insert = 1 + count(s1,s2.substr(1), dp);
            int del = 1 + count(s1.substr(1),s2, dp);
            int replace = 1 + count(s1.substr(1),s2.substr(1), dp);
            return dp[i][j] = min(insert, min(del, replace));
        }
    }
};
