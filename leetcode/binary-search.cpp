class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, start = 0, end = nums.size() - 1;
        while (end >= start) {
            mid = (start + end) >> 1;
            if (target < nums[mid])
                end = mid - 1;
            else if (target > nums[mid])
                start = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};
