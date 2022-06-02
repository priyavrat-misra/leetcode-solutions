class Solution {
public:
    int specialArray(vector<int>& nums) {
        int m, lo = 0, hi = nums.size(), cnt;
        while (lo <= hi) {
            m = (lo + hi) / 2;
            cnt = 0;
            for (int& num : nums)
                if (num >= m)
                    ++cnt;
            if (cnt > m)
                lo = m + 1;
            else if (cnt < m)
                hi = m - 1;
            else
                return m;
        }
        return -1;
    }
};
