//Time:  O(N);
//Space: O(N);
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        if(size<2)
            return nums;
        vector<int> ans;
        unordered_map<int, int> map;
        unordered_map<int, bool> found;
        for(int i=0;i<size;i++){
            map[nums[i]]++;
            if(map[nums[i]] > (double)size/3)
                if(found.find(nums[i]) == found.end()){
                    found[nums[i]] = true;
                    ans.push_back(nums[i]);
                }
        }
        return ans;
    }
};
