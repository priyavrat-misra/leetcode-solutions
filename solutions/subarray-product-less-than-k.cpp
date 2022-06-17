class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, prod = 1, n = nums.size();
        for (int l = 0, r = 0; r < n; ++r) {
            prod *= nums[r];
            while (l <= r && prod >= k)
                prod /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};
