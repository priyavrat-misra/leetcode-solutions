class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k}); // {x, y, distance, k}
        while (!q.empty()) {
            vector<int> f = std::move(q.front());
            q.pop();
            int x = f[0], y = f[1];
            
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;
            
            if (x == m - 1 && y == n - 1)
                return f[2];
            
            if (grid[x][y] == 1)
                if (f[3] > 0)
                    f[3]--;
                else
                    continue;
            
            if (visited[x][y] != -1 && visited[x][y] >= f[3])
                continue;
            
            visited[x][y] = f[3];
            
            q.push({x + 1, y, f[2] + 1, f[3]});
            q.push({x - 1, y, f[2] + 1, f[3]});
            q.push({x, y + 1, f[2] + 1, f[3]});
            q.push({x, y - 1, f[2] + 1, f[3]});
        }
        return -1;
    }
};
