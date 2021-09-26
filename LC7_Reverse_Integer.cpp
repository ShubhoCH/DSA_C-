#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        for (int i = 0; x != 0; i++) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if (ans > 2147483647 || ans < -2147483648)
            return 0;
        return ans;
    }
};
int main() {
    int t,n;
    cin >> t;
    Solution S;
    while (t--) {
        cin >>n;
        cout << S.reverse(n) << endl;
    }
}
