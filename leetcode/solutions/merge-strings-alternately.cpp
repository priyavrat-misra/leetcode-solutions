class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        string merged;
        int m = word1.size(), n = word2.size();
        int i, s = m < n ? m : n;
        for (i = 0; i < s; ++i) {
            merged.push_back(word1[i]);
            merged.push_back(word2[i]);
        }
        if (m - n) {
            if (s == m)
                merged += word2.substr(i, n);
            else
                merged += word1.substr(i, m);
        }
        return merged;
    }
};
