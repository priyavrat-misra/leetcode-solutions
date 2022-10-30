class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n + 1);
        count[0] = 0;
        for (int i = 1; i <= n; ++i)
            count[i] = count[i/2] + i % 2;
        
        return count;
    }
};
