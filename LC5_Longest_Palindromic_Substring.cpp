#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int l = 0, r = -1;
    int Check(string& s, int i, int j) {
        if (j > s.length() - 1)
            return 1;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            int len = max(Check(s, i, i), Check(s, i, i + 1));
            if (len > r-l+1) {
                l = i - ((len - 1) / 2);
                r = i + len / 2;
            }
        }
        return s.substr(l, r-l+1);
    }
};
int main() {
    string s;
    int t;
    cin >> t;
    Solution S;
    while (t--) {
        cin >> s;
        S.l = 0;
        S.r = -1;
        cout << S.longestPalindrome(s) << endl;
    }
}
