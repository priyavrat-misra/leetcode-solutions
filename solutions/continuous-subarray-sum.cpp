class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int presum = 0;
        unordered_map<int, int> mod;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            presum += nums[i];
            presum %= k;
            cout << presum << " ";
            if (presum == 0 && i)
                return true;
            if (mod.count(presum)) {
                if (i - mod[presum] > 1)
                    return true;
            } else
                mod[presum] = i;
        }
        return false;
    }
};
