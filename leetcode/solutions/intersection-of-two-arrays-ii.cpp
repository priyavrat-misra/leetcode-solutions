class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int mx = max(
            *max_element(nums1.begin(), nums1.end()),
            *max_element(nums2.begin(), nums2.end())
        );
        vector<int> f(mx + 1, 0);
        for (int& i : nums1)
            ++f[i];
        
        vector<int> v;
        for (int& i : nums2)
            if (f[i]) {
                v.push_back(i);
                --f[i];
            }
        return v;
    }
};
