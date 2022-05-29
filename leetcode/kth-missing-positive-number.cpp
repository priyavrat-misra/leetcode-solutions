class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int m, lo = 0, hi = arr.size();
        while (lo < hi) {
            m = (lo + hi) / 2;
            if (arr[m] - m - 1 < k)
                lo = m + 1;
            else
                hi = m;
        }
        return lo + k;
    }
};
