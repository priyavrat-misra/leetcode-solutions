class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0, mx = 0, mn = INT_MAX;
        for (int& s : salary) {
            mx = max(mx, s);
            mn = min(mn, s);
            sum += s;
        }
        return 1.0 * (sum - mx - mn) / (salary.size() - 2);
    }
};
