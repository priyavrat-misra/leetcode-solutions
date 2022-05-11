class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_curr, max_gl;
        max_curr = max_gl = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            max_curr = max(nums[i], max_curr + nums[i]);
            if (max_gl < max_curr)
                max_gl = max_curr;
        }
        return max_gl;
    }
};
