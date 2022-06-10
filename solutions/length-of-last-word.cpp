class Solution {
public:
    int lengthOfLastWord(string& s) {
        int ans = 0;
        string::reverse_iterator i = s.rbegin(), j = s.rend();
        while (*i == ' ')
            ++i;
        while (i != j && *i != ' ') {
            ++ans;
            ++i;
        }
        return ans;
    }
};
