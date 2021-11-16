//Time:  O(N^2);
//Space: O(N);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size()-1].size()+1,0);
        for(int i=triangle.size()-1;i>=0;i--)
            for(int j=0;j<=i;j++)
                dp[j] = triangle[i][j] + ((dp[j] < dp[j+1])?dp[j]:dp[j+1]);
        return dp[0];
    }
};
