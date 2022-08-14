class Solution {
public:
    int rearrangeCharacters(string& s, string& target) {
        unordered_map<char, int> targetFreq, sFreq;
        for (char& c : target)
            ++targetFreq[c];
        
        for (char& c : s)
            ++sFreq[c];
        
        int res = INT_MAX;
        for (pair<const char, int>& row : targetFreq)
            res = min(res, sFreq[row.first] / row.second);
        
        return res;
    }
};
