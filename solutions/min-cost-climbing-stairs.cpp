class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);
        
        int first = cost[0], second = cost[1], curr;
        for (int i = 2; i < n; ++i) {
            curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        return min(first, second);
    }
};
