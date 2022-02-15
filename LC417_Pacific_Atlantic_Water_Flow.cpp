//Time:  O(N^2);
//Space: O(N^2);
class Solution {
public:
    void helper(vector<vector<int>>& h, vector<vector<bool>>& map, int i, int j){
        map[i][j] = true;
        if(i+1<h.size() && h[i+1][j] >= h[i][j] && map[i+1][j]!=true)
            helper(h,map,i+1,j);
        if(j+1<h[0].size() && h[i][j+1] >= h[i][j] && map[i][j+1]!=true)
            helper(h,map,i,j+1);
        if(i-1>=0 && h[i-1][j] >= h[i][j] && map[i-1][j]!=true)
            helper(h,map,i-1,j);
        if(j-1>=0 && h[i][j-1] >= h[i][j] && map[i][j-1]!=true)
            helper(h,map,i,j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific (heights.size(), vector<bool>(heights[0].size()));
        vector<vector<bool>> atlantic (heights.size(), vector<bool>(heights[0].size()));
        for(int i=0;i<heights.size();i++){
            helper(heights,pacific, i, 0);
            helper(heights,atlantic, i, heights[0].size()-1);
        }
        for(int j=0;j<heights[0].size();j++){
            helper(heights,pacific, 0, j);
            helper(heights,atlantic, heights.size()-1, j);
        }
        vector<vector<int>> ans;
        for(int i=0;i<heights.size();i++)
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        return ans;
    }
};
