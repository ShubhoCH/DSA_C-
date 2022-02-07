//Time:  O(S*P);
//Space: O(P);
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> pmap;
        unordered_map<char,int> smap;
        for(int i=0;i<p.length();i++){
            pmap[p[i]]++;
            smap[s[i]]++;
        }
        int l=0;
        vector<int> ans;
        if(pmap==smap)
            ans.push_back(0);
        for(int i=p.length();i<s.length();i++){
            smap[s[i]]++;
            if(smap[s[l]] == 1)
                smap.erase(s[l]);
            else
                smap[s[l]]--;
            l++;
            if(smap == pmap) ans.push_back(l);
        }
        return ans;
    }
};
