//Not Good:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1, next = 2;
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= 0)
                continue;
            map[nums[i]] = i;
            if(nums[i] == ans){
                ans = next;
                ans++;
                while(map.find(ans) != map.end()) ans++;
            }
            
        }
        return ans;
    }
};


//O(N):
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= 0)
                continue;
            map[nums[i]] = i;
        }
        while(true){
            if(map.find(ans) != map.end())
                ans++;
            else
                break;
        }
        return ans;
    }
};
