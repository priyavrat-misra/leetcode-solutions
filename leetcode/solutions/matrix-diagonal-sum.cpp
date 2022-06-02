class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() - 1, ans = 0;
        if (n == 0)
            return mat[0][0];
        for (int i = 0; i <= n; ++i)
            ans += mat[i][i] + mat[i][n-i];
        return n % 2 ? ans : ans - mat[n/2][n/2];
    }
};
