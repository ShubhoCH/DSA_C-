//Time:  O(N*M);
//Space: O(N*M);
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp;
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        for(int i=0;i<=m;i++){
            vector<int> temp;
            for(int j=0;j<=n;j++)
                temp.push_back(-1);
            dp.push_back(temp);
        }
        return findTotalWays(m,n,0,0,dp, obstacleGrid);
    }
    int findTotalWays(int m,int n, int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if(obstacleGrid[i][j] == 1){
            dp[i][j] = 0;
            return 0;
        }
        if(i == m-1 && j == n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int down = 0, right = 0;
        if(i<m - 1)
            down = findTotalWays(m,n,i + 1,j,dp, obstacleGrid);
        if(j<n - 1)
            right = findTotalWays(m,n,i,j + 1,dp, obstacleGrid);
        return dp[i][j] = down + right;
    }
};
