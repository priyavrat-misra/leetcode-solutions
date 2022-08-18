class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo <= hi) {
            if (nums[lo] <= nums[hi])
                return nums[lo];
            int mid = lo + (hi - lo) / 2;
            int next = (mid + 1) % n, prev = (mid + n - 1) % n;
            if (nums[next] > nums[mid] && nums[prev] > nums[mid])
                return nums[mid];
            if (nums[lo] > nums[mid])
                hi = mid - 1;
            else if (nums[mid] > nums[hi])
                lo = mid + 1;
        }
        return -1;
    }
};
