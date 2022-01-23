//Time:  O(2^N);
//Space: O(1);
class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> temp, int i, vector<int>& nums){
        if(i>= nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(ans, temp, i+1, nums);
        temp.pop_back();
        helper(ans, temp, i+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,temp,0, nums);
        return ans;
    }
};
