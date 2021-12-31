//Time:  O(N^2);
//Space: O(N);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        ans[nums.size() - 1] = 1;
        int maxx =  1;
        for(int i=nums.size()-1;i>=0;i--)
            for(int j = i+1; j<nums.size();j++){
                if(nums[j]>nums[i])
                    ans[i] = max(ans[i], 1+ans[j]);
                if(ans[i] > maxx)
                    maxx = ans[i];
            }
        return maxx;
    }
};
