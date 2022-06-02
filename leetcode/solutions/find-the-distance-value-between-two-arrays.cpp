class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0, m, lo, hi, flag, s = arr2.size() - 1;
        for (int& n : arr1) {
            lo = 0, hi = s, flag = 1;
            while (lo <= hi) {
                m = (lo + hi) >> 1;
                if (arr2[m] < n)
                    lo = m + 1;
                else if (arr2[m] > n)
                    hi = m - 1;
                else {
                    flag = 0;
                    break;
                }
            }
            hi = max(0, hi);
            lo = min(lo, s);
            if (flag && min(abs(n - arr2[lo]), abs(n - arr2[hi])) > d)
                ++ans;
        }
        return ans;
    }
};
