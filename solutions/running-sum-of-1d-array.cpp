class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (auto it = nums.begin() + 1; it != nums.end(); ++it)
            *it += *(it - 1);
        return nums;
    }
};
