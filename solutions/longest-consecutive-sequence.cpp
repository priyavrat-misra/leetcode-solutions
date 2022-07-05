class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size())
            return 0;
        
        int ans = 1;
        unordered_map<int, bool> m;
        for (int& num : nums)
            m[num] = true;
        
        vector<int> nodes;
        for (pair<const int, bool>& row : m)
            nodes.push_back(row.first);
        
        for (int& node : nodes) {
            if (m[node]) {
                int len = 1, n = node;
                m[node] = false;
                while (m[--n]) {
                    ++len;
                    m[n] = false;
                }
                n = node;
                while (m[++n]) {
                    ++len;
                    m[n] = false;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
