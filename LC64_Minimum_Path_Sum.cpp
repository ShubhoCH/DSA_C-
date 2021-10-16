//Time:  O(N^2);
//Space: O(N^2);
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 1 && grid[0].size() == 1)
            return grid[0][0];
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++)
            for(int j=0;j<m;j++){
                dp[i][j] = grid[i][j];
                if(i>0 && j>0)
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                else if(i>0)
                    dp[i][j] += dp[i-1][j];
                else if(j>0)
                    dp[i][j] += dp[i][j-1];
            }
        return dp[n-1][m-1];
    }
};
