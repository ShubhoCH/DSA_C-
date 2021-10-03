class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(target > nums[right])
            return right+1;
        if(target < nums[left])
            return 0;
        while(left<=right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
