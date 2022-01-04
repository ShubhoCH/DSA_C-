//Time:  O(N);
//Space: O(N);
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, int> m1, m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto it = m1.begin();it!=m1.end();it++){
            if(it->second != m2[it->first])
                return false;
        }
        return true;
    }
};
