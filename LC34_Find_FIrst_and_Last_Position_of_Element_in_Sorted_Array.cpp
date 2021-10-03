//O(logN):
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left,right;
        left = 0,  right = nums.size()-1;
        if(right == -1)
            return {-1,-1};
        else if(target > nums[right] || target < nums[left])
            return {-1,-1};
        vector<int> ans = {-1,-1};
        while(left<=right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                left = right = mid;
                left = searchLeft(nums, target, left);
                right = searchRight(nums, target, right);
                ans[0] = left;
                ans[1] = right;
                return ans;
            }else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
    int searchLeft(vector<int>& nums, int target, int val){
        int left = 0;
        int right = val - 1;
        while(left<=right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return searchLeft(nums, target, mid);
            else
                left = mid + 1;
        }
        return val;
    }
    int searchRight(vector<int>& nums, int target, int val){
        int left = val + 1;
        int right = nums.size() - 1;
        while(left<=right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return searchRight(nums, target, mid);
            else
                right = mid - 1;
        }
        return val;
    }
};
