class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int max_p = 0, min_st = prices[0];
        for (int i = 1; i < n; ++i) {
            max_p = max(max_p, prices[i] - min_st);
            min_st = min(min_st, prices[i]);
        }
        return max_p;
    }
};
