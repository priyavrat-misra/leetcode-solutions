class Solution {
public:
    vector<int> countDigits(int n) {
        vector<int> freq(10);
        while (n) {
            ++freq[n%10];
            n /= 10;
        }
        return freq;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> freq = countDigits(n);
        for (int i = 0; i < 31; ++i)
            if (freq == countDigits(1 << i))
                return true;
        
        return false;
    }
};
