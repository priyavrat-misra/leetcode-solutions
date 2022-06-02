class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while (n) {
            if (n % 2)
                ++ones;
            n >>= 1;
        }
        return ones;
    }
};
