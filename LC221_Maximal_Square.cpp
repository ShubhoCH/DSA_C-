//Time:  O(N*M);
//Space: O(N*M);
class Solution {
   public:
   int maximalSquare(vector<vector<char>>& matrix) {
      int ans = 0;
      int n = matrix.size();
      if(!n)return 0;
      int c = matrix[0].size();
      vector<vector<int>> m(n, vector <int> (c));
      for(int i =0;i<n;i++){
         for(int j = 0; j<c;j++){
            m[i][j] = matrix[i][j] - '0';
            ans = max(m[i][j],ans);
         }
      }
      for(int i =n-2;i>=0;i--){
         for(int j =1;j<c;j++){
            if(m[i][j]){
               m[i][j] = 1 + min({m[i+1][j],m[i][j-1],m[i+1][j-1]});
            }
            ans = max(ans,m[i][j]);
         }
      }
      return ans*ans;
   }
};
