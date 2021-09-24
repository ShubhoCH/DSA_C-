#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1, i2, index = nums1.size() + nums2.size();
        double ans = 0;
        if (index % 2 != 0)
            index = index / 2;
        else
            index = index / 2 - 1;
        cout << "Index: " << index << endl;
        for (i1 = 0, i2 = 0; i1 + i2 <= index;) {
            if (i1 < nums1.size() && i2 < nums2.size()) {
                if (nums1[i1] <= nums2[i2]) {
                    if (i1 + i2 == index)
                        ans = nums1[i1];
                    i1++;
                }
                else {
                    if (i1 + i2 == index)
                        ans = nums2[i2];
                    i2++;
                }
            }
            else {
                if (i1 < nums1.size()) {
                    if (i1 + i2 == index)
                        ans = nums1[i1];
                    i1++;
                }
                else {
                    if (i1 + i2 == index)
                        ans = nums2[i2];
                    i2++;
                }
            }
        }
        cout << "i1: " << i1 << " i2: " << i2 << endl;
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            if (i1 < nums1.size() && i2 < nums2.size()) {
                if (nums1[i1] <= nums2[i2])
                    ans += nums1[i1];
                else
                    ans += nums2[i2];
            }
            else {
                if (i1 < nums1.size())
                    ans += nums1[i1];
                else
                    ans += nums2[i2];
            }
            ans /= 2;
        }
        return ans;
    }
};
int main() {
    vector<int> v1{2};
    vector<int> v2{0};
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2);
}
