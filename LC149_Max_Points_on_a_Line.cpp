//Time:  O(N^2);
//Space: O(N);
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        if(size<3)
            return size;
        int ans = 0;
        for(int i=0;i<size;i++){
            unordered_map<double, int> map;
            for(int j=i+1;j<size;j++){
                int x = (points[j][0] - points[i][0]);
                int y = (points[j][1] - points[i][1]);
                double slope;
                if(x!=0)
                    slope = (double)y/x;
                else
                    slope = (double)INT_MAX;
                if(map.find(slope) == map.end())
                    map[slope] = 1;
                else
                    map[slope]++;
                if(map[slope] > ans)
                    ans = map[slope];
            }
        }
        return ans + 1;
    }
};
