class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), max_d = 0;
        for (int i = 0; i < m; ++i) {
            int mid, lo = i, hi = n - 1;
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;
                if (nums1[i] > nums2[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            max_d = max(max_d, hi - i);
        }
        return max_d;
    }
};
