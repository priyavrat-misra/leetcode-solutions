class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, lo = 0, hi = nums.size();
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else if (nums[mid] > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};
