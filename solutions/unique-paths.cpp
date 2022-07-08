class Solution {
public:
    int uniquePaths(int& m, int& n) {
	// (m+n)!/m!n!
        if (m == 1 && n == 1)
            return 1;
        if (m < n)
            return uniquePaths(n, m);
        --m;
        --n;
        long ans = 1;
        for (int i = m + 1, j = 1; i <= m + n; ++i, ++j) {
            ans *= i;
            ans /= j;
        }
        return int(ans);
    }
};
