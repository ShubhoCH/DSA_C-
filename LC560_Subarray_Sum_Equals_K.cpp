//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int sum = 0, ans = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)
                ans++;
            if(map.find(sum-k) != map.end())
                ans+=map[sum-k];
            map[sum]++;
        }
        return ans;
    }
};
