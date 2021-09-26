#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string Roman(int n) {
        vector<int> v = { 1,5,10,50,100,500,1000 };
        vector<string> vv = { "I","V","X","L","C","D","M" };
        string s = "";
        while (n > 0) {
            auto it = upper_bound(v.begin(), v.end(), n);
            int index = it - v.begin() - 1;
            n -= v[index];
            s += vv[index];
        }
        return s;
    }
    string intToRoman(int num) {
        int digits = (num > 999) ? 4 : (num > 99) ? 3 : (num > 9) ? 2 : 1;
        unordered_map<int, string> map{ {4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"} };
        string ans = "";
        for (int i = 0; i < digits; i++) {
            int temp = pow(10, i) * (num % 10);
            if (map.find(temp) != map.end())
                ans = map[temp] + ans;
            else
                ans = Roman(temp) + ans;
            num = num / 10;
        }
        return ans;
    }
};
