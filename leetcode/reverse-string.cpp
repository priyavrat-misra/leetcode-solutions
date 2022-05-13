class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator i = s.begin(), j = s.end() - 1;
        while (i < j) {
            swap(*i, *j);
            ++i;
            --j;
        }
    }
};
