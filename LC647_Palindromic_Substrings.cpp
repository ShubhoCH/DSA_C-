//Time:  O(N^2);
//Space: O(1);
class Solution {
public:
    int helper(string s, int i, int j){
        int ans = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            ans++;
            i--;
            j++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            ans+=helper(s,i,i);
            ans+=helper(s,i,i+1);
        }
        return ans;
    }
};
