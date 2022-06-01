class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> pow;
        int i = 0, j = mat[0].size(), p;
        for (vector<int>& row : mat) {
            p = 0;
            while (p < j && row[p])
                ++p;
            pow.push_back({p, i});
            ++i;
        }
        sort(pow.begin(), pow.end());
        vector<int> ans(k);
        for (int i = 0; i < k; ++i)
            ans[i] = pow[i].second;
        
        return ans;
    }
};
