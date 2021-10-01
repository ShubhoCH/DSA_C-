class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)
                nums[temp++] = nums[i];
            else
                while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return temp;
    }
};
