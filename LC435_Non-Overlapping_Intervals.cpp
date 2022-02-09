//Time:  O(NlogN);
//Space: O(1);
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 0;
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        int l = 0,r = 1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[l][1]>intervals[r][0]){
                if(intervals[l][1] < intervals[r][1])
                    r++;
                else{
                    l = r;
                    r++;
                }
                ans++;
            }else{
                l = r;
                r++;
            }
        }
        return ans;
    }
};
