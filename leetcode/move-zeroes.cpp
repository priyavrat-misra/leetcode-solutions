class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j, n = nums.size();
        for (i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                j = i + 1;
                for (; j < n && !nums[j]; ++j) {}
                if (j == n)
                    break;
                nums[i] = nums[j];
                nums[j] = 0;
            }
        }
    }
};
