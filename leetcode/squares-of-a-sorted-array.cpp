class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (auto i = nums.begin(); i != nums.end(); ++i)
            *i *= *i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
