//Time:  O(N*M);
//Space: O(N*M);
class Solution {
public:
    int findTotalWays(int m,int n, int i, int j, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int down = 0, right = 0;
        if(i<m)
            down = findTotalWays(m,n,i + 1,j,dp);
        if(j<n)
            right = findTotalWays(m,n,i,j + 1,dp);
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for(int i=0;i<=m;i++){
            vector<int> temp;
            for(int j=0;j<=n;j++)
                temp.push_back(-1);
            dp.push_back(temp);
        }
        return findTotalWays(m,n,0,0,dp);
    }
};
