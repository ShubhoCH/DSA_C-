#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findIndex(char c) {
        vector<char> str = { 'I','V','X','L','C','D','M' };
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
    int romanToInt(string s) {
        vector<int> v = { 1,5,10,50,100,500,1000 };
        int ans = v[findIndex(s[s.length()-1])];
        for (int i = s.length() - 2; i >= 0; i--) {
            int i1 = findIndex(s[i]);
            int i2 = findIndex(s[i+1]);
            if (v[i2] > v[i1])
                ans -= v[i1];
            else
                ans += v[i1];
        }
        return ans;
    }
};
int main() {
    int t;
    string s;
    cin >> t;
    Solution S;
    while (t--) {
        cin >>s;
        cout << S.romanToInt(s) << endl;
    }
}
