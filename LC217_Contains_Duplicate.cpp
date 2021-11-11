//Time:  O(N);
//Space: O(N);
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i]) != map.end())
                return true;
            map[nums[i]] = true;
        }
        return false;
    }
};
