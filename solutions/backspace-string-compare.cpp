class Solution {
public:
    bool backspaceCompare(string& s, string& t) {
        int skip_s = 0, skip_t = 0;
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    --i;
                    ++skip_s;
                } else if (skip_s) {
                    --i;
                    --skip_s;
                } else
                    break;
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    --j;
                    ++skip_t;
                } else if (skip_t) {
                    --j;
                    --skip_t;
                } else
                    break;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            if ((i >= 0) != (j >= 0))
                return false;
            --i;
            --j;
        }
        return true;
    }
};
