class Solution {
public:
    void solve(vector<vector<int>>& ans, int start, vector<int> temp, vector<int>& candidates, int target){
        if(target < 0)
            return;
        if(target == 0)
            ans.push_back(temp);
        for(int i=start;i<candidates.size();i++){
            if(i>start and candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            solve(ans, i + 1, temp, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, 0, temp, candidates, target);
        return ans;
    }
};
