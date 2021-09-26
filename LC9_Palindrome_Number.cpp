class Solution {
public:
    bool Check(string s, int i, int j, int n){
        while(i>=0 && j<n){
            if(s[i] == s[j]){
                i--;
                j++;
            }
            else
                return false;
        }
        return true;
    }
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s = to_string(x);
        if(s.length()%2!=0)
            return Check(s, s.length()/2, s.length()/2, s.length());
        return Check(s, s.length()/2-1, s.length()/2, s.length());
    }
};
