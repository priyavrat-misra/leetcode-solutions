class Solution {
public:
    string freqAlphabets(string& s) {
        int k = s.size() - 1;
        for (auto i = s.rbegin(); i != s.rend(); ++i) {
            if (*i == '#') {
                i += 2;
                s[k] = (*i - '0') * 10 + (*(i - 1) - '0') + 96;
            } else {
                s[k] = (*i - '0') + 96;
            }
            --k;
        }
        return s.substr(k + 1, s.size());
    }
};
