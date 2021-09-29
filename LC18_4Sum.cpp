class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        int n = nums.size();
        if (n < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int temp = target - (nums[i] + nums[j]);
                for (int k = j + 1, l = n - 1; l > k;) {
                    if (temp == nums[k] + nums[l]) {
                        ans.push_back({ nums[i], nums[j], nums[k], nums[l] });
                        int temp2 = nums[k];
                        while (k < l && nums[k] == temp2) k++;
                        temp2 = nums[l];
                        while (k < l && nums[l] == temp2) l--;
                    }
                    else if (temp > nums[k] + nums[l])
                        k++;
                    else
                        l--;
                }
                while (j < n - 2 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 3 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
