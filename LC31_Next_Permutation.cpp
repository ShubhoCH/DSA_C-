class Solution {
public:
    // O(N^2)
    void swapAndSort(vector<int>& nums, int i){
        int index = i;
        for(int j=i+1;j<nums.size();j++)
            if(nums[j] > nums[i])
                if(index == i)
                    index = j;
                else if(nums[index] > nums[j])
                    index = j;
        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;
        sort(nums.begin()+i+1,nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        bool needed = false;
        for(int i=nums.size()-2;i>=0;i--)
            if(nums[i]<nums[i+1]){
                needed = true;
                swapAndSort(nums,i);
                break;
            }
        sort(nums.begin(), nums.end());
    }
    //Little bit Optimised faster than 81.22% (3ms)
    void swapAndSort(vector<int>& nums, int i){
        int index = i;
        while(index < nums.size()-1 && nums[index+1] > nums[i]) index++;
        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;
        sort(nums.begin()+i+1,nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        bool needed = false;
        for(int i=nums.size()-2;i>=0;i--)
            if(nums[i]<nums[i+1]){
                needed = true;
                swapAndSort(nums,i);
                return;
            }
        sort(nums.begin(), nums.end());
    }
};
