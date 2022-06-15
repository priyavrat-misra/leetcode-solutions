class Solution {
    // next permutation logic
public:
    int reverse(int num, int& rev, int& base) {
        if (num > 0) {
            reverse(num / 10, rev, base);
            rev += (num % 10) * base;
            base *= 10;
        }
        return rev;
    }
    
    int nextGreaterElement(int n) {
        if (n < 10)
            return -1;
        
        int m = n;
        long t = n, k1 = 10, k2 = 1;
        int i = (n % 100) / 10, j = n % 10; 
        while (i >= j && n / (k1 * 10)) {
            j = i;
            k1 *= 10;
            i = (n % (k1 * 10)) / k1;
        }
        
        j = n % 10;
        while (i >= j && n > 10) {
            k2 *= 10;
            n /= 10;
            j = n % 10;;
        }
        t += (k1 - k2) * (j - i);  // t - i * k1 + j * k1 - j * k2 + i * k2;
        int x = 0, y = 1;
        t = t - (t % k1) + reverse(t % k1, x , y);
        return t > m && t <= INT_MAX ? t : -1;
    }
};
