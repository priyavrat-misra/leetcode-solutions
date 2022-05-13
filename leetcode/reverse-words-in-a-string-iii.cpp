class Solution {
public:
    string reverseWords(string s) {
        string::iterator i = s.begin(), j = i + 1, k;
        while (i < s.end()) {
            while (*j != ' ' and j < s.end())
                ++j;
            k = j--;
            while (i < j) {
                swap(*i, *j);
                ++i;
                --j;
            }
            i = k + 1;
            j = i + 1;
        }
        return s;
    }
};
