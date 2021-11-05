//Time:  O(N^2);
//Space: O(N);
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0) return true;
        vector<bool> dp(s.length() + 1, false);
        set<string> ss;
        int maxLength = 0;
        for(int i=0;i<wordDict.size();i++){
            ss.insert(wordDict[i]);
            if(wordDict[i].length() > maxLength)
                maxLength = wordDict[i].length();
        }
        dp[0] = true;
        for(int i=1;i<dp.size();i++)
            for(int j=i-1;j>=0;j--){
                if(i-j > maxLength)
                    break;
                if(dp[j] && ss.find(s.substr(j,i-j)) != ss.end()){
                    dp[i] = true;
                    break;
                }
            }
        return dp[s.length()];
    }
};
