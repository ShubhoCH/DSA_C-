//Time:  O(N);
//Space: O(1);
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int minn, maxx, ans = INT_MIN;
        minn = maxx = 1;
        for(int i=0;i<nums.size();i++)
            if(ans<nums[i])
                ans = nums[i];
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                minn = maxx = 1;
                continue;
            }
            int temp = maxx * nums[i];
            maxx = max(max(maxx * nums[i], minn * nums[i]), nums[i]);
            minn = min(min(temp , minn * nums[i]), nums[i]);
            ans = max(maxx,ans);
        }
        return ans;
    }
};
