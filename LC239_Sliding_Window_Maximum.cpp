//Time:  O(N);
//Space: O(N);
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int, int>> q;
        q.push_back({0, nums[0]});
        for(int i=1;i<k;i++){
            while(!q.empty() && q.back().second < nums[i])
                q.pop_back();
            q.push_back({i, nums[i]});
        }
        ans.push_back(q.front().second);
        for(int i=k;i<nums.size();i++){
            if(q.front().first <= i - k)
                q.pop_front();
            while(!q.empty() && q.back().second < nums[i])
                q.pop_back();
            q.push_back({i, nums[i]});
            ans.push_back(q.front().second);
        }
        return ans;
    }
};
