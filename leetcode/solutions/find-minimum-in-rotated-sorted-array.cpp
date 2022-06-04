class Solution {
public:
    int findMin(vector<int>& nums) {
        int hi = nums.size() - 1;
        if (hi == 0)
            return nums[0];
        
        int mid, lo = 0;
        if (nums[hi] > nums[0])
            return nums[0];
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid+1] < nums[mid])
                return nums[mid+1];
            if (nums[mid-1] > nums[mid])
                return nums[mid];
            if (nums[mid] > nums[0])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return 0;
    }
};
