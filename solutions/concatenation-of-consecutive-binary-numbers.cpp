class Solution {
public:
    inline int noOfBits(int& i) {
        return log2(i) + 1;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0;
        int i = 1, MOD = 1e9 + 7;
        while (i <= n)
            ans <<= noOfBits(i), ans |= i++, ans %= MOD;
        
        return ans;
    }
};
