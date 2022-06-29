class Solution {
public:
    int longestPalindrome(string& s) {
        int ans = 0;
        vector<int> freq(128);
        for (char& c : s)
            if (++freq[c] == 2) {
                ans += 2;
                freq[c] = 0;
            }
        return ans == s.size() ? ans : ans + 1;
    }
};
