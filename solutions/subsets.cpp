class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for (int& num : nums) {
            int s = ans.size();
            for (int i = 0; i < s; ++i) {
                vector<int> subset = ans[i];
                subset.push_back(num);
                ans.push_back(subset);
            }
        }
        return ans;
    }
};
