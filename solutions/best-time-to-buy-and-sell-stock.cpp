class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int max_profit = 0, min_stock = prices[0];
        for (int i = 1; i < n; ++i) {
            max_profit = max(max_profit, prices[i] - min_stock);
            min_stock = min(min_stock, prices[i]);
        }
        return max_profit;
    }
};
