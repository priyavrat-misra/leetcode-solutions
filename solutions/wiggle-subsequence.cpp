class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 1, currDiff, prevDiff = 0;
        for (int i = 1; i < n; ++i) {
            currDiff = nums[i] - nums[i-1];
            if ((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)) {
                ++ans;
                prevDiff = currDiff;
            }
        }
        return ans;
    }
};
