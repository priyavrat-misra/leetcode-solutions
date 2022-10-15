class Solution {
public:
    int m, n;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int area = 0;
        if (grid[i][j]) {
            grid[i][j] = 0;
            ++area;
            if (i > 0)
                area += dfs(grid, i - 1, j);
            if (i < m - 1)
                area += dfs(grid, i + 1, j);
            if (j > 0)
                area += dfs(grid, i, j - 1);
            if (j < n - 1)
                area += dfs(grid, i, j + 1);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    max_area = max(max_area, dfs(grid, i, j));
        
        return max_area;
    }
};
