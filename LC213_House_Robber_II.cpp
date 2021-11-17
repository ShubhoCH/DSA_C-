//Time:  O(N);
//Space: O(1);
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(helper(nums, 0), helper(nums,1));
    }
    int helper(vector<int>& nums, int s){
        int a1,a2;
        a1 = nums[0+s];
        a2 = max(nums[1+s], nums[0+s]);
        for(int i=2;i<nums.size()-1;i++){
            int temp = a2;
            a2 = max(nums[i+s] + a1, a2);
            a1 = temp;
        }
        return a2;
    }
};
