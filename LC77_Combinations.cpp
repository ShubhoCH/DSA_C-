//Time:  O(N^K);
//Space: O(logN);
class Solution {
public:
    void helper(int n, int k, int height, int curr, vector<int> temp, vector<vector<int>>& ans){
        if(height == k){
            ans.push_back(temp);
            return;
        }
        for(int i = curr;i<=n;i++){
            temp.push_back(i);
            helper(n,k,height+1,i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n,k,0,1,temp,ans);
        return ans;
    }
};
