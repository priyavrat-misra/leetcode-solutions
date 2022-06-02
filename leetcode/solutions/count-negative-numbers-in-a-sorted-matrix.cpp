class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            int mid, lo = 0, hi = n;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (grid[i][mid] > -1)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            ans += (n - hi) * (m - i);
            n = hi;
        }
        return ans;
    }
};
