#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        vector<vector<char> > v(numRows);
        int dir = 1;
        for (int i = 0, j = 0; i < s.length(); i++) {
            v[j].push_back(s[i]);
            if (numRows != 1) {
                (dir == 1) ? j++ : j--;
                if (j == numRows) {
                    dir = -1;
                    j = j - 2;
                }
                else if (j == -1) {
                    dir = +1;
                    j = j + 2;
                }
            }
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                ans += v[i][j];
            }
        }
        return ans;
    }
};
int main() {
    string s;
    int t,n;
    cin >> t;
    Solution S;
    while (t--) {
        cin >> s>>n;
        cout << S.convert(s, n) << endl;
    }
}
