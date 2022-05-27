class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int lo = 0, hi = x, m;
        while (lo <= hi) {
            m = lo + (hi - lo) / 2;
            if (m < x / m)
                lo = m + 1;
            else if (m > x / m)
                hi = m - 1;
            else
                return m;
        }
        return hi;
    }
};
