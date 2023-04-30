class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;

    int solve(int start, string& s, int& k, vector<int>& dp) {
        if (start == n)
            return 1;
        if (s[start] == '0')
            return 0;
        if (dp[start])
            return dp[start];
        int ans = 0;
        long num = 0;
        for (int end = start; end < n; ++end) {
            num = (num * 10) + s[end] - '0';
            if (num > k)
                break;
            ans = (ans % MOD + solve(end + 1, s, k, dp) % MOD) % MOD;
        }
        return dp[start] = ans;
    }

    int numberOfArrays(string s, int k) {
        n = s.size();
        vector<int> dp(n, 0);
        return solve(0, s, k, dp);    
    }
};
