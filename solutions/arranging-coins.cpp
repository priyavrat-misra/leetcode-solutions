class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n;
        long curr, k;
        while (lo <= hi) {
            k = lo + (hi - lo) / 2;
            curr = k * (k + 1) / 2;
            if (n == curr)
                return k;
            if (curr > n)
                hi = k - 1;
            else
                lo = k + 1;
        }
        return hi;
    }
};
