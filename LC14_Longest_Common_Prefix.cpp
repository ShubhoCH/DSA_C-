class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = strs[0].length();
        string s = strs[0];
        for(int i=1;i<strs.size();i++){
            if(strs[i].length()<min){
                s = strs[i];
                min = strs[i].length();
            }
        }
        for(int i=0;i<min;i++)
            for(int j=0;j<strs.size();j++)
                if(strs[j][i] != s[i])
                    return s.substr(0,i);
        return s;
    }
};
