#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int maxProfit(vector<int>& p) {
       if(p.size() <= 1) return 0;
       if(p.size() == 2 && p[1]>p[0]) return p[1] - p[0];
       else if(p.size() == 2) return 0;
       vector<vector<int>> dp(p.size(),vector<int>(2,0));
       dp[0][0] = 0;
       dp[0][1] = -p[0];
       dp[1][0] = max(dp[0][0], dp[0][1] + p[1]);
       dp[1][1] = max(dp[0][1], dp[0][0] - p[1]);
       for(int i=2;i<p.size();i++){
           dp[i][0] = max(dp[i-1][0], dp[i-1][1] + p[i]);
           dp[i][1] = max(dp[i-1][1], dp[i-2][0] - p[i]);
       }
       return dp[p.size()-1][0];
   }
};
