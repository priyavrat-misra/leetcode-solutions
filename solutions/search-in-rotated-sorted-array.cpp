class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, lo = 0, hi = nums.size(), n;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            // if both are on the same side
            if ((nums[mid] < nums[0]) == (target < nums[0]))
                n = nums[mid];
            else
                n = target < nums[0] ? INT_MIN : INT_MAX;
            
            if (n < target)
                lo = mid + 1;
            else if (n > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};
