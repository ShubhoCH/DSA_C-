class Solution {
public:
    void solve(vector<vector<int>>& ans, int start, vector<int> temp, vector<int>& candidates, int target){
        if(target < 0)
            return;
        if(target == 0)
            ans.push_back(temp);
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(ans, i, temp, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        solve(ans, 0, temp, candidates, target);
        return ans;
    }
};
