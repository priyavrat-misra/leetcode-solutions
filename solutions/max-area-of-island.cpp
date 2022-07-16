class Solution {
public:
    int dfs(vector<vector<int>>& grid, const int& i, const int& j) {
        int area = 0;
        if (grid[i][j]) {
            ++area;
            grid[i][j] = 0;
            if (i > 0)
                area += dfs(grid, i - 1, j);
            if (i < grid.size() - 1)
                area += dfs(grid, i + 1, j);
            if (j > 0)
                area += dfs(grid, i, j - 1);
            if (j < grid[0].size() - 1)
                area += dfs(grid, i, j + 1);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j])
                    max_area = max(max_area, dfs(grid, i, j));
        
        return max_area;
    }
};
