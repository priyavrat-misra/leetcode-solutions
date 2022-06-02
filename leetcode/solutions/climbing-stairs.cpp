class Solution {
public:
    int climbStairs(int n) {
        if (n < 4)
            return n;
        int a = 2, b = 3, ans;
        for (int i = 4; i <= n; ++i) {
            ans = b + a;
            a = b;
            b = ans;
        }
        return ans;
    }
};
