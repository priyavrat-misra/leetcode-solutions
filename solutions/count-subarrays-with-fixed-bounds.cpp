class Solution {
	public:
		long long countSubarrays(vector<int>& nums, int minK, int maxK) {
			long long ans = 0;
			int bad = -1, mn = -1, mx = -1, start = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] < minK || nums[i] > maxK)
					bad = i;
				if (nums[i] == minK)
					mn = i;
				if (nums[i] == maxK)
					mx = i;
				start = min(mn, mx);
				if (start > bad)
					ans += start - bad;
			}
			return ans;
		}
};
