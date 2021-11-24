//Time:  O(1);
//Space: O(1);
class Solution {
public:
    unordered_map<string,string> mp;
    int num = 0;
    string encode(string longUrl) {
        num++;
        string addon = to_string(num);
        string ans = "http://tinyurl.com/";
        ans+=string(addon);
        mp[ans] = longUrl;
        return ans;
    }
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};
