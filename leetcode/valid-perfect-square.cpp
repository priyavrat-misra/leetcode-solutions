class Solution {
public:
    bool isPerfectSquare(int num) {
        int m, i = 1, j = num;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (m < num / m)
                i = m + 1;
            else if (m > num / m)
                j = m - 1;
            else
                return num % m == 0;
        }
        return false;
    }
};
