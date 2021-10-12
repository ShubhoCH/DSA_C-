// Time: O(N);
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        if(newInterval.size() == 0 || intervals.size() == 0){
            temp.push_back(newInterval);
            return newInterval.size() == 0 ? intervals : temp;
        }
        if(newInterval[1] < intervals[0][0]){
            temp.push_back(newInterval);
            for(int i=0;i<intervals.size();i++)
                temp.push_back(intervals[i]);
            return temp;
        }
        vector<vector<int>> ans;
        int size = intervals.size();
        bool chk = true;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
                continue;
            } else{
                chk = false;
                int start = min (intervals[i][0], newInterval[0]);
                int end;
                ++i;
                while( i < size && intervals[i][0] <= newInterval[1]) ++i;
                --i;
                if(intervals[i][0] > newInterval[1])
                     end = newInterval[1];
                else{
                    end = max(intervals[i][1], newInterval[1]);
                    ++i;
                }
                ans.push_back({start, end});
                while(i < size){
                    ans.push_back(intervals[i]);
                    ++i;
                }
            }
        }
        if(chk){
            ans.push_back(newInterval);
        }
        return ans;
    }
};
