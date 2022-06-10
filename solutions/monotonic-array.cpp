class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool incr = true, decr = true;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] > nums[i])
                incr = false;
            if (nums[i-1] < nums[i])
                decr = false;
        }
        return incr || decr;
    }
};
