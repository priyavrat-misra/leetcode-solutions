class Solution {
public:
    int N, M;
    const int MOD = 1e9 + 7;
    int dp[101][101][101];
    
    int solve(int i, int p, int ppl, int& minProfit, vector<int>& group, vector<int>& profit) {
        if (ppl > N)
            return 0;

        if (i == M)
            return p >= minProfit;

        if (dp[i][p][ppl] != -1)
            return dp[i][p][ppl];

        int not_taken = solve(i + 1, p, ppl, minProfit, group, profit) % MOD;
        int taken = solve(i + 1, min(p + profit[i], minProfit), ppl + group[i], minProfit, group, profit) % MOD;
        return dp[i][p][ppl] = ((long) not_taken + taken) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        M = group.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, minProfit, group, profit);
    }
};
