class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
      int n = nums.size();
      long res = 0, sum = 0;
      for (int i = 0; i < n; ++i) {
          sum += nums[i];
          res = max(res, (sum + i) / (i + 1));
      }
      return res;
    }
};
