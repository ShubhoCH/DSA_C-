//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[1], nums[0]));
        for(int i=2;i<nums.size();i++){
            int temp = max(nums[i] + dp[i-2], dp[i-1]);
            dp.push_back(temp);
        }
        return dp[nums.size() - 1];
    }
};

