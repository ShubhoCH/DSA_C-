//Time:  O(N);
//Space: O(N);
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> ans;
        if(s.length() < 11)
            return ans;
        for(int i=0;i<=s.length() - 10;i++){
            if(map.find(s.substr(i,10)) != map.end())
            {
                if(map[s.substr(i,10)] == 1){
                    ans.push_back(s.substr(i,10));
                    map[s.substr(i,10)]++;
                }
            }else
                map[s.substr(i,10)] = 1;
        }
        return ans;
    }
};
