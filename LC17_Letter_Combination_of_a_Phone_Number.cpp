class Solution {
public:
    void getString(string digits, vector<string>& v, unordered_map<char, string>& map, string s, int i){
        if(s.length() == digits.length()){
            v.push_back(s);
            return ;
        }
        string val = map[digits[i]];
        for(char x: val)
            getString(digits,v,map,s+x,i+1);
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> v;
        if(digits.length()<1)
            return v;
        unordered_map<char, string> map = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        getString(digits, v, map, "", 0);
        return v;
    }
};
