//Time:  O(N);
//Space: O(1);
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = nums[0], count_zero = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=0)
                 p*=nums[i];
            else
                count_zero++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                if(!count_zero)
                    nums[i] = p/nums[i];
                else    
                    nums[i] = 0;
            else
                if(count_zero > 1)
                    nums[i] = 0;
                else
                    nums[i] = p;
        }
        return nums;
    }
};
