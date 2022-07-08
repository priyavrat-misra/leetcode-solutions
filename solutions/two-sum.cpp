class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> m(n);
        for (int i = 0; i < n; ++i)
            m[i] = {nums[i], i};
        
        sort(m.begin(), m.end());
        int i = 0, j = n - 1;
        while (i < j) {
            if (m[i].first + m[j].first > target)
                --j;
            else if (m[i].first + m[j].first < target)
                ++i;
            else
                return {m[i].second, m[j].second};
        }
        return {};
    }
};
