class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1)
            return {1};
        
        vector<int> LR(n, 1), RL(n, 1);
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1])
                LR[i] = LR[i-1] + 1;
        
        for (int i = n - 2; i >= 0; --i)
            if (ratings[i] > ratings[i+1])
                RL[i] = RL[i+1] + 1;
        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += max(LR[i], RL[i]);
        
        return ans;
    }
};
