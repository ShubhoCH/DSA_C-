//Time:  O(N*logN);
//Space: O(N);
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(int i=0;i<nums.size();i++)
            s.push_back(to_string(nums[i]));
        sort(s.begin(), s.end(), [](string s1, string s2){
            return s1+s2 > s2+s1;
        });
        string ans = "";
        for(auto x: s)
            ans += x;
        return (ans[0] == '0') ? "0" : ans;
    }
};
