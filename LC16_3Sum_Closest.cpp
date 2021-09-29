class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[nums.size()-1];
        for(int i=0;i<n-2;i++)
            for(int j=i+1, k = n-1;j<k;){
                int temp = nums[i]+nums[j]+nums[k];
                if(abs(temp - target) < abs(ans - target))
                    ans = temp;
                if(temp < target)
                    j++;
                else if(temp > target)
                    k--;
                else
                    return target;
            }
        return ans;
    }
};
