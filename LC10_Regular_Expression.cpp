#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Check(string s, string p, int i, int j) {
        if (i >= s.length() && j >= p.length())
            return true;
        if (j >= p.length())
            return false;
        if (i == s.length()) {
            if (p[j] == '.')
                return false;
            if (j < p.length() - 1 && p[j + 1] == '*')
                return Check(s, p, i, j + 2);
            return false;
        }
        if (j < p.length() - 1 && p[j+1] == '*') {
            if (p[j] == '.')
                return Check(s, p, i + 1, j);
            if (s[i] != p[j] && p[j]!='.')
                return Check(s, p, i, j + 2);
            return Check(s, p, i + 1, j) || Check(s, p, i, j + 2);
        }
        if (s[i] == p[j] || p[j] == '.')
            return Check(s, p, i + 1, j + 1);
        else
            return false;
    }
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        return Check(s, p, i, j);
    }
};
int main() {
    string s1, s2;
    int t;
    cin >> t;
    Solution S;
    while (t--) {
        cin >>s1>>s2;
        cout << S.isMatch(s1,s2) << endl;
    }
}
