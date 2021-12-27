//Time:  O(M*N);
//Space: O(M*N);
class Solution {
public:
   int ar[1001][1001];
   int longestCommonSubsequence(string text1, string text2) {
       int m = text1.size();
       int n = text2.size();
       memset(ar ,-1 , sizeof(ar));
       return helper( text1,  text2, m, n);
   }
   int helper(string &text1, string &text2, int m, int n){
       if(m == 0 || n == 0) return 0;  //base condition
       if(ar[m][n] != -1) return ar[m][n]; // use of memoization. 
       if(text1[m-1] == text2[n-1])
           return ar[m][n] = (1+helper(text1, text2,m-1,n-1));
       else return ar[m][n]= max(helper(text1, text2,m-1,n),helper(text1, text2,m,n-1));
   }
};
