class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        long rev = 0;
        int t = x;
        while (t) {
            rev *= 10;
            rev += t % 10;
            t /= 10;
        }
        return x == rev;
    }
};
