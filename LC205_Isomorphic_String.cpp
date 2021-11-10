//Time:  O(N);
//Space: O(N);
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map;
        unordered_map<char,char>map2;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i]) == map.end()){
                if(map2.find(t[i]) != map2.end())
                    return false;
                map[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else
                if(t[i]!=map[s[i]] || map2[t[i]] != s[i])
                    return false;
        }
        return true;
    }
};
