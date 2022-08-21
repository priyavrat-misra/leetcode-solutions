class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int m, lo = 0, hi = letters.size();
        while (lo < hi) {
            m = lo + (hi - lo) / 2;
            if (letters[m] <= target)
                lo = m + 1;
            else
                hi = m;
        }
        return letters[hi % letters.size()];
    }
};
