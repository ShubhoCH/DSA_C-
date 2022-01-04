//Time:  O(N);
//Space: O(1);
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans, sum;
        ans = sum = 0;
        bool zero = false;
        for(int i=0;i<nums.size();i++){
            ans+=i+1;
            sum+=nums[i];
            if(nums[i] == 0) zero = true;
        }
        if(!zero) return 0;
        if(ans == sum) return nums.size();
        return ans - sum;
        // unordered_map<int, bool> map;
        // for(auto x: nums)
        //     map[x] = true;
        // if(map.find(0) == map.end())
        //     return 0;
        // int ans = INT_MAX;
        // for(int i=0;i<nums.size();i++){
        //     if(map.find(nums[i]+1)==map.end() && nums[i] + 1 < ans)
        //         ans = nums[i] + 1;
        // }
        // return ans;
    }
};
