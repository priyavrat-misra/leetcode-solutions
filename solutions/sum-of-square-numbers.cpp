class Solution {
public:
    bool judgeSquareSum(int c) {
        int j = sqrt(c);
        if (j * j == c)
            return true;
        int i = 0;
        while (i <= j) {
            if (i * i < c - j * j)
                ++i;
            else if (i * i > c - j * j)
                --j;
            else
                return true;
        }
        return false;
    }
};
