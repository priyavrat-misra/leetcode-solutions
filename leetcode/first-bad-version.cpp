// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s, mid, start = 0, end = n - 1;
        while (end >= start) {
            mid = start + (end - start)/2;
            if (isBadVersion(mid)) {
                end = mid - 1;
                s = mid;
            } else {
                start = mid + 1;
            }
        }
        return s;
    }
};
