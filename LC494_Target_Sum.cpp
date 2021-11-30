//Time:  O(N*S) S=> Sum of the entire array!
//Space: O(N*S);
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        map<pair<int, int>, int> vis;
        find(nums, target, ans, 0, vis);
        return ans;
    }
    int find(vector<int>& nums, int target, int& ans, int i,map<pair<int,int>, int>& vis){
        if(i==nums.size()) {
            if(target == 0){
                ans++;
                return 1;
            }
            return 0;
        }
        if(vis.find({i,target}) != vis.end()){
            ans += vis[{i,target}];
            return vis[{i,target}];
        }
        int take = 0;
        int rem = 0;
        take = find(nums, target + nums[i], ans, i+1, vis);
        rem = find(nums, target - nums[i], ans, i+1, vis);
        return vis[{i,target}] = take + rem;
    }
};
