class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size(), wins = n - k + 1;
        vector<int> lft(n), rgt(n);

        lft[0] = nums.front();
        for (int i = 1; i < n; i++) {
            if (i % k != 0)
                lft[i] = max(lft[i - 1], nums[i]);
            else
                lft[i] = nums[i];
        }

        rgt[n - 1] = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            if (i % k != (k - 1))
                rgt[i] = max(nums[i], rgt[i + 1]);
            else
                rgt[i] = nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < wins; i++)
            ans.push_back(max(rgt[i], lft[i + k - 1]));
        
        return ans;
    }
};
