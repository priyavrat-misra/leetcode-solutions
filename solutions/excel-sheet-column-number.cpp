class Solution {
public:
    int titleToNumber(string& s) {
        int ans = 0;
        long base = 1;
        string::reverse_iterator it = s.rbegin();
        while (it != s.rend()) {
            ans += base * (*it - 64);
            base *= 26;
            ++it;
        }
        return ans;
    }
};
