// Time: O([k=1 to N] P(N,k))
// Space: O(N) + O(N) + O(N^2) = O(N^2)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==1){
            ans.push_back(nums);
            return ans;
        }
        sort(nums.begin(),nums.end());
        vector<bool> v;
        for(int i=0;i<nums.size();i++)
            v.push_back(false);
        vector<int> temp;
        solve(ans, nums, v, temp, 0);
        return ans;
    }
    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<bool> v, vector<int> temp, int index){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(v[i] == true) continue;
            v[i] = true;
            temp.push_back(nums[i]);
            solve(ans,nums,v,temp,index+1);
            temp.pop_back();
            v[i] = false;
            while(i<nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        return;
    }
};
