class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1)
                    ans = max(ans, count(grid, i, j));
            }
        }
        return ans;
    }
    int count(vector<vector<int>>& grid, int i, int j)
    {
        if(grid[i][j] == 0)
            return 0;
        int sum = 1;
        grid[i][j] = 0;
        if(i>0)
            sum += count(grid, i-1, j);
        if(i<grid.size()-1)
            sum += count(grid, i+1, j);
        if(j<grid[0].size()-1)
            sum += count(grid, i, j+1);
        if(j>0)
            sum += count(grid, i, j-1);
        return sum;
    }
};
