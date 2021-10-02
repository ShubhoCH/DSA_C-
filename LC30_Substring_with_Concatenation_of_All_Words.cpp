class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length();
        vector<int> ans;
        if(len*words.size() > s.length())
            return ans;
        unordered_map<string, int> map;
        for(int i=0;i<words.size();i++){
            if(map.find(words[i])!=map.end())
                map[words[i]] += 1;
            else
                map[words[i]] = 1;
        }
        for(int i=0,j;i<=s.length()-len*words.size();i++){
            unordered_map<string, int> map2;
            for(j=i;j-i<len*words.size();j+=len){
                if(map.find(s.substr(j,len)) != map.end()){
                    if(map2.find(s.substr(j,len)) == map2.end())
                        map2[s.substr(j,len)] = 1;
                    else if(map2[s.substr(j,len)] < map[s.substr(j,len)])
                        map2[s.substr(j,len)] += 1;
                    else
                        break;
                }
                else
                    break;
            }
            if(j-i >= len * words.size())
                ans.push_back(i);
        }
        return ans;
    }
};
