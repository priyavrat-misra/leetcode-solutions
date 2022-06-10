class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, start, end, total_subarrs, odd_subarrs;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            end = i + 1;
            start = n - i;
            total_subarrs = end * start + 1;
            /* #subarrays with arr[i]
             * = #subarrays that end with arr[i]
             * * #subarrays that start with arr[i]
             * and + 1 to get rid of the following condition
             */
            // odd_subarrs = total_subarrs / 2 if total_subarrs is odd then ++odd_subarrs;
            odd_subarrs = total_subarrs / 2;
            ans += odd_subarrs * arr[i];
        }
        return ans;
    }
};
