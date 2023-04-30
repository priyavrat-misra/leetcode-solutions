class Solution {
public:
    int m, k;
    const int MOD = 1e9 + 7;

    int solve(int i, int j, vector<vector<long>>& freq, string& target, vector<vector<int>>& dp) {
        if (i == m)
            return 1;
        if (j == k)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int not_taken = solve(i, j + 1, freq, target, dp) % MOD;
        int taken = freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target, dp) % MOD;
        return dp[i][j] = (not_taken + taken) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        m = target.size();
        k = words[0].size();
        vector<vector<long>> freq(26, vector<long>(k));
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        for (string& word : words)
            for (int col = 0; col < k; ++col)
                ++freq[word[col] - 'a'][col];
        
        cout << dp[1][543];
        return solve(0, 0, freq, target, dp);
    }
};
