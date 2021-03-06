class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        
        int a = 1, b = 1, c;
        while (--n) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
