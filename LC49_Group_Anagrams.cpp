// Time: O(MlogM*N + N)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> map;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(map.find(s) == map.end()){
                ans.push_back({strs[i]});
                map[s] = ans.size() - 1;
            }else{
                ans[map[s]].push_back(strs[i]);
            }
        }
        return ans;
    }
};
