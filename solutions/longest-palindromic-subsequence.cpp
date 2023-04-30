class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n));
        return lps(s, 0, n - 1, memo);
    }

    int lps(string& s, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j])
            return memo[i][j];
        if (i > j)
            return 0;
        if (i == j)
            return 1;

        if (s[i] == s[j])
            return memo[i][j] = lps(s, i + 1, j - 1, memo) + 2;
        else
            return memo[i][j] = max(lps(s, i + 1, j, memo), lps(s, i, j - 1, memo));
    }
};
