class Solution {
public:
    string minWindow(string s, string t) {
        int remaining[128]{0};
        for (char& c : t)
            ++remaining[c];
        
        int left = 0, right = 0, start = left;
        int required = t.size(), n = s.size();
        int len = INT_MAX;
        while (left < n) {
            if (required) {
                if (right == n)
                    break;
                --remaining[s[right]];
                if (remaining[s[right]] >= 0)
                    --required;
                ++right;
            } else {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                ++remaining[s[left]];
                if (remaining[s[left]] > 0)
                    ++required;
                ++left;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
