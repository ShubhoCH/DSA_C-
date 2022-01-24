class Solution {
public:
   int minStickers(vector<string>& stickers, string target) {
      int n = target.size();
      int N = 1 << n;
      vector <int> dp(N, INT_MAX);
      dp[0] = 0;
      for(int i = 0; i < N; i++){
         if(dp[i] == INT_MAX) continue;
         for(int j = 0; j < stickers.size(); j++){
            string s = stickers[j];
            int x = i;
            for(int k = 0; k < s.size(); k++){
               char z = s[k];
               for(int l = 0; l < target.size(); l++){
                  if(target[l] == z && ((x >> l) & 1) == 0){
                     x |= (1 << l);
                     break;
                  }
               }
            }
            dp[x] = min(dp[x], dp[i] + 1);
         }
      }
      return dp[N - 1] == INT_MAX? -1 : dp[N - 1];
   }
};
