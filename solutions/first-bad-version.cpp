// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, lo = 0, hi = n;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (isBadVersion(m))
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};
