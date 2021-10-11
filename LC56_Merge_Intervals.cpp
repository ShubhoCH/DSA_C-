// Time:  O(NlogN);
// Space: O(logN) or O(N);
class Solution {
public:
    bool compare(vector<int> v1, vector<int> v2){
        return v1[1] < v2[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<intervals.size();i++){
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            while(i<intervals.size()-1 && temp[1] >= intervals[i+1][0]){
                temp[1] = max(temp[1] ,intervals[i+1][1]);
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
