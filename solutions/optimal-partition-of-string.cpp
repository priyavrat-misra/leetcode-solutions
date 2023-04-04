class Solution {
public:
    int partitionString(string s) {
        int ans = 1, freq = 0;
        for (char& c : s) {
            if (freq & (1 << (c - 'a')))
                ++ans, freq = 0;
            freq |= (1 << (c - 'a'));
        }
        return ans;
    }
};
