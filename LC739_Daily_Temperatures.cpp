//Time:  O(N);
//Space: O(N);
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> s;
        vector<int> ans(temp.size());
        for(int i=0;i<temp.size();i++){
            if(s.empty() || temp[i]<s.top().second)
                s.push({i,temp[i]});
            else{
                while(!s.empty() && temp[i]>s.top().second){
                    ans[s.top().first] = i - s.top().first;
                    s.pop();
                }
                s.push({i,temp[i]});
            }
        }
        while(!s.empty()){
            ans[s.top().first] = 0;
            s.pop();
        }
        return ans;
    }
};
