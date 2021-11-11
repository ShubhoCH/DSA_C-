//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp;
        dp.push_back(1);
        (s[0]!='0')?dp.push_back(1):dp.push_back(0);
        for(int i = 2;i<=s.length();i++){
            int onedigit = s[i-1] - '0';
            int twodigit = stoi(s.substr(i-2,2));
            int sum = 0;
            if(onedigit >= 1)
                sum += dp[i-1];
            if(twodigit >= 10 && twodigit <= 26)
                sum += dp[i-2];
            dp.push_back(sum);
        }
        return dp[s.length()];
    }
};
