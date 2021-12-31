class Solution {
   public:
   int maxCoins(vector<int>& a) {
      int n = a.size();
      if(!n)return 0;
      vector < vector <int>> dp(n,vector <int> (n));
      for(int l = n-1;l>=0;l--){
         for(int r=l;r<n;r++){
            for(int i =l;i<=r;i++){
               dp[l][r] = max(dp[l][r],(i-1>=0?dp[l][i-1]:0) +(i+1<n?dp[i+1][r]:0)+((l-1>=0?a[l-1]:1 )*(r+1<n?a[r+1]:1)*a[i]));
            }
         }
      }
      return dp[0][n-1];
   }
};
