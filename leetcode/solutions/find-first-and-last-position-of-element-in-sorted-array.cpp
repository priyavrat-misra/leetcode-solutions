class Solution {
public:
    int startPos(vector<int>& nums, const int& target) {
        int m, lo = 0, hi = nums.size();
        while (lo < hi) {
            m = (lo + hi) / 2;
            if (nums[m] < target)
                lo = m + 1;
            else
                hi = m;
        }
        return hi;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        
        int lower = startPos(nums, target);
        if (lower == nums.size() || nums[lower] != target)
            return {-1, -1};
        
        int upper = startPos(nums, target + 1);
        return {lower, upper - 1};
    }
};
