//Time:  O(N);
//Space: O(1);
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int size = 0, end = 0;
        unordered_map<char, int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            size++;
            end = max(end, map[s[i]]);
            if(i==end){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};
