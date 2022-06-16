class Solution {
public:
    vector<int> findAnagrams(string& s, string& p) {
        int m = s.size(), n = p.size();
        if (m < n)
            return {};
        vector<int> freq_s(26), freq_p(26), ans;
        for (char& c : p)
            ++freq_p[c-'a'];
        for (int i = 0; i < n; ++i)
            ++freq_s[s[i]-'a'];
        for (int i = n; i < m; ++i) {
            if (freq_s == freq_p)
                ans.push_back(i - n);
            --freq_s[s[i-n]-'a'];
            ++freq_s[s[i]-'a'];
        }
        if (freq_s == freq_p)
            ans.push_back(m - n);
        return ans;
    }
};
