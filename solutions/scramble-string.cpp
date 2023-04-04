class Solution {
public:
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;

        int n = s1.size();
        int freq[26]{0};
        for (int i = 0; i < n; ++i)
            ++freq[s1[i] - 'a'], --freq[s2[i] - 'a'];
        for (int& i : freq)
            if (i)
                return false;
        if (n <= 3)
            return true;
        if (dp.count(s1 + s2))
            return dp[s1 + s2];
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return dp[s1 + s2] = true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return dp[s1 + s2] = true;
        }
        return dp[s1 + s2] = false;
    }
};
