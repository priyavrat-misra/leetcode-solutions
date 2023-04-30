class Solution {
public:
    int n;

    int calc(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (dp[i][k])
            return dp[i][k];
        if (i == n || k == 0)
            return 0;
        int ans = calc(i + 1, k, piles, dp);
        int takeCoins = 0;
        for (int j = 0; j < piles[i].size() && j < k; ++j) {
            takeCoins += piles[i][j];
            ans = max(ans, takeCoins + calc(i + 1, k - (j + 1), piles, dp));
        }
        return dp[i][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        return calc(0, k, piles, dp);
    }
};
