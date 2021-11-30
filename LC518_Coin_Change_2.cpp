//Time:  O(N*M);
//Space: O(N*M);
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0 || amount == 1) return 1;
        vector<vector<int> > dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return coinchange(coins, amount, coins.size(), dp);
    }
    int coinchange(vector<int>& a, int v, int n, vector<vector<int> >& dp)
    {
        if (v == 0)
            return dp[n][v] = 1;
        if (n == 0)
            return 0;
        if (dp[n][v] != -1)
            return dp[n][v];
        if (a[n - 1] <= v) 
            return dp[n][v] = coinchange(a, v - a[n - 1], n, dp) + coinchange(a, v, n - 1, dp);
        else
            return dp[n][v] = coinchange(a, v, n - 1, dp);
    }
};
