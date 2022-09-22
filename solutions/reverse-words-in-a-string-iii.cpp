class Solution {
public:
    string reverseWords(string& s) {
        string::iterator i = s.begin(), j = i + 1, k, end = s.end();
        while (i < end) {
            while (*j != ' ' && j < end)
                ++j;
            
            k = j--;
            while (i < j)
                swap(*i, *j), ++i, --j;
            
            i = k + 1;
            j = i + 1;
        }
        return s;
    }
};
