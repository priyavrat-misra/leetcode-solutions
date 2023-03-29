class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0, n = satisfaction.size();
        int sum = satisfaction[n - 1];
        int val = satisfaction[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sum += satisfaction[i];
            val += sum;
            if (val > ans)
                ans = val;
        }
        return ans;
    }
};
