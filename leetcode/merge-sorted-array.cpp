class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums = {nums1.begin(), nums1.begin() + m};
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums[i] < nums2[j]) {
                nums1[i+j] = nums[i];
                ++i;
            } else {
                nums1[i+j] = nums2[j];
                ++j;
            }
        }
        while (i < m) {
            nums1[i+j] = nums[i];
            ++i;
        }
        while (j < n) {
            nums1[i+j] = nums2[j];
            ++j;
        }
    }
};
