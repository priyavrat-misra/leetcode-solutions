class Solution {
public:
    int m, n;

    void dfs(const int& r, const int& c, vector<vector<int>>& grid) {
        if (!grid[r][c]) {
            grid[r][c] = 1;
            if (r > 0)
                dfs(r - 1, c, grid);
            if (r < m - 1)
                dfs(r + 1, c, grid);
            if (c > 0)
                dfs(r, c - 1, grid);
            if (c < n - 1)
                dfs(r, c + 1, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int r = 0; r < m; ++r)
            dfs(r, 0, grid), dfs(r, n - 1, grid);
        for (int c = 1; c < n - 1; ++c)
            dfs(0, c, grid), dfs(m - 1, c, grid);
        
        int totalIslands = 0;
        for (int r = 1; r < m - 1; ++r)
            for (int c = 1; c < n - 1; ++c)
                if (!grid[r][c])
                    dfs(r, c, grid), ++totalIslands;
        
        return totalIslands;
    }
};
