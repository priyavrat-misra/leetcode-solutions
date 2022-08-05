class Solution {
public:
    string licenseKeyFormatting(string& s, int k) {
        string res;
        string::reverse_iterator it = s.rbegin();
        while (true) {
            int i = k;
            while (i && it != s.rend()) {
                if (*it >= 'a')
                    res.push_back(*it - 32), --i;
                else if (*it != '-')
                    res.push_back(*it), --i;
                ++it;
            }
            if (it == s.rend())
                break;
            res.push_back('-');
        }
        reverse(res.begin(), res.end());
        return res[0] == '-' ? string(res.begin() + 1, res.end()) : res;
    }
};
