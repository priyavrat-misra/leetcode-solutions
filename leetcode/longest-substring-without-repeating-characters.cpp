class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();
        
        int right = 0, left = 0, ans = 0;
        vector<int> freq(128, -1);
        while (right < s.size()) {
            char r = s[right];
            ++freq[r];
            while (freq[r]) {
                --freq[s[left]];
                ++left;
            }
            ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};
