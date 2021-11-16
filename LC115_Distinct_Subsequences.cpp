//Time:  O(M*N);
//Space: O(M*N);
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1, -1));
        return count(s,t,0,0, dp);
    }
    int count(string s, string t, int i ,int j, vector<vector<int>>& dp){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j])
            dp[i][j] = count(s,t, i+1, j+1, dp) + count(s, t, i+1, j, dp);
        else
            dp[i][j] = count(s, t, i+1, j, dp);
        return dp[i][j];
    }
};
