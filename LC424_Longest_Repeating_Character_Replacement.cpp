//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int l,r,ans = 0, max_freq = 0;
        l=r=0;
        for(;r<s.length();r++){
            map[s[r]]++;
            if(map[s[r]] > max_freq)
                max_freq = map[s[r]];
            if((r - l + 1) - max_freq <= k)
                ans = max(ans, (r - l + 1));
            else{
                while(!((r - l + 1) - max_freq <= k)){
                    map[s[l]]--;
                    l++;
                }
            }
        }
        return ans;
    }
};
