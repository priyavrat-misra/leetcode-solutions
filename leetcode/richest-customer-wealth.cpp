class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN, curr;
        for (vector<int>& customer : accounts) {
            curr = 0;
            for (int& money : customer)
                curr += money;
            mx = max(mx, curr);
        }
        return mx;
    }
};
