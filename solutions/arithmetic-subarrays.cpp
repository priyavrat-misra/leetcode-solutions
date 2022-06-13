class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans(m, true);
        for (int i = 0; i < m; ++i) {
            vector<int> n(vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1));
            sort(n.begin(), n.end());
            
            int diff = n[1] - n[0];
            int s = r[i] - l[i] + 1;
            for (int j = 2; j < s; ++j) {
                if (n[j] - n[j-1] != diff) {
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};
