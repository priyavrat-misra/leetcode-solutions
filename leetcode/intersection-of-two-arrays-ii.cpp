class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector<int> v;
        int mx = max(
            *max_element(nums1.begin(), nums1.end()),
            *max_element(nums2.begin(), nums2.end())
            );
        vector<int> f(mx + 1, 0);
        for (int i = 0; i < m; ++i)
            ++f[nums1[i]];
        for (int j = 0; j < n; ++j)
            if (f[nums2[j]]) {
                --f[nums2[j]];
                v.push_back(nums2[j]);
            }
        return v;
    }
};
