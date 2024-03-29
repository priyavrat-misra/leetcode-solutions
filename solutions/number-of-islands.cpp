class Solution {
public:
    void dfs(vector<vector<char>>& grid, const int& i, const int& j) {
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            if (i > 0)
                dfs(grid, i - 1, j);
            if (i < grid.size() - 1)
                dfs(grid, i + 1, j);
            if (j > 0)
                dfs(grid, i, j - 1);
            if (j < grid[0].size() - 1)
                dfs(grid, i, j + 1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1')
                    ++ans, dfs(grid, i, j);
        
        return ans;
    }
};
