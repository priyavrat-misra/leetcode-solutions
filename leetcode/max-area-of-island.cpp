class Solution {
public:
    int dfs(vector<vector<int>>& grid, const int& i, const int& j) {
        int ans = 0;
        if (grid[i][j]) {
            ++ans;
            grid[i][j] = 0;
            if (i > 0)
                ans += dfs(grid, i - 1, j);
            if (i < grid.size() - 1)
                ans += dfs(grid, i + 1, j);
            if (j > 0)
                ans += dfs(grid, i, j - 1);
            if (j < grid[0].size() - 1)
                ans += dfs(grid, i, j + 1);
        }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j])
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};
