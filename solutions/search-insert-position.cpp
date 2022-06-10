class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, lo = 0, hi = nums.size();
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return hi;
    }
};
