#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //Using Sorting:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)return {};
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        result.push_back({ nums[i], nums[j], nums[k] });
                        while (j < k && nums[j] == nums[j + 1]) j++;
                        while (j < k && nums[k] == nums[k - 1]) k--;
                        j++;
                        k--;
                    }
                    else if (sum > 0) k--;
                    else j++;
                }
            }
        }
        return result;
    }
};
int main() {
    int t,n;
    vector<int> v;
    cin >> t;
    Solution S;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        vector<vector<int> > vv = S.threeSum(v);
        for (int i = 0; i < vv.size(); i++) {
            cout << vv[i].at(0)<<" " << vv[i].at(1) << " " << vv[i].at(2) << " ";
        }
    }
}
