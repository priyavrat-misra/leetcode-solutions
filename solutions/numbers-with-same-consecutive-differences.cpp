class Solution {
public:
    vector<int> ans;
    void solve(int n, int& k, int num, int& digit) {
        if (n == 0) {
            ans.push_back(num);
            return;
        }
        for (int i = 0; i < 10; ++i)
            if (abs(i - digit) == k)
                solve(n - 1, k, 10 * num + i, i);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; ++i)
            solve(n - 1, k, i, i);
        
        return ans;
    }
};
