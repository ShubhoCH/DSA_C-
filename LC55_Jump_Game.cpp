// Time:  O(N);
// Space: O(1);
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rechable = 0;
        for(int i=0;i<=rechable && rechable < nums.size() - 1;i++){
            if(nums[i] + i > rechable)
                rechable = nums[i] + i;
        }
        if(rechable >= nums.size() - 1)
            return true;
        return false;
    }
};
