class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        return n - lps(s, 0, n - 1, dp);
    }

    int lps(string& s, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j])
            return dp[i][j];
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (s[i] == s[j])
            return dp[i][j] = lps(s, i + 1, j - 1, dp) + 2;
        else
            return dp[i][j] = max(lps(s, i + 1, j, dp), lps(s, i, j - 1, dp));
    }
};
