class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        string merged;
        int m = word1.size(), n = word2.size();
        int i = 0, j = m < n ? m : n;

        while (i < j)
            merged.push_back(word1[i]), merged.push_back(word2[i]), ++i;
        if (i < m)
            merged += word1.substr(i, m);
        if (i < n)
            merged += word2.substr(i, n);

        return merged;
    }
};
