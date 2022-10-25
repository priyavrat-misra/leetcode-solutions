class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int x = 0, x1 = 0, x2 = 0;
        for (unsigned i = 0; i < n; ++i)
            x ^= (i + 1) ^ nums[i];
        
        x &= -x;
        for (unsigned i = 0; i < n; ++i) {
            (nums[i] & x) ? x1 ^= nums[i] : x2 ^= nums[i];
            ((i + 1) & x) ? x1 ^= (i + 1) : x2 ^= (i + 1);
        }
        
        for (int& num : nums)
            if (num == x1)
                return {x1, x2};
        
        return {x2, x1};
    }
};
