class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;
        for (int& num : nums) {
            if (!num)
                ++count;
            else
                ans += (count * (count + 1)) / 2, count = 0;
        }
        ans += (count * (count + 1)) / 2;
        return ans;
    }
};