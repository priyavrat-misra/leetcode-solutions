class Solution {
public:
    int n, ans = 0;
    
    int uniqueChars(string& s) {
        bitset<128> f;
        for (char& c : s) {
            if (f[c])
                return 0;
            else
                f.set(c);
        }
        return s.size();
    }
    
    void solve(vector<string>& arr, string s, int idx = 0) {
        if (idx == n) {
            ans = max(ans, uniqueChars(s));
            return;
        }
        solve(arr, s, idx + 1);
        solve(arr, s + arr[idx], idx + 1);
    }
    
    int maxLength(vector<string>& arr) {
        n = arr.size();
        solve(arr, "");
        return ans;
    }
};
