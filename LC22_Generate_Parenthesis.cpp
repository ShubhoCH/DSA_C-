class Solution {
public:
    void GetString(int n, vector<string>& v, int open, int close, string s){
        if(s.length() == n * 2){
            v.push_back(s);
            return;
        }
        if(open<n)
            GetString(n,v,open+1,close,s+'(');
        if(close < open)
            GetString(n,v,open,close+1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        int open=0, close = 0;
        vector<string> v;
        GetString(n,v,open,close,"");
        return v;
    }
};
