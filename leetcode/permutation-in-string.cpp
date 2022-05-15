class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;
        
        vector<int> s1freq(26, 0), s2freq(26, 0);
        for (const char& c : s1)
            ++s1freq[c - 'a'];
        
        for (int i = 0; i < m; ++i)
                ++s2freq[s2[i] - 'a'];
        
        for (int i = 0; i < n - m; ++i) {
            if (s1freq == s2freq)
                return true;
            --s2freq[s2[i] - 'a'];
            ++s2freq[s2[i+m] - 'a'];
        }

        return s1freq == s2freq ? true : false;
    }
};
