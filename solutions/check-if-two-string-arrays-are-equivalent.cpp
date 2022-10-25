class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (string& word : word1)
            s1 += word;
        
        for (string& word : word2)
            s2 += word;
        
        return s1 == s2;
    }
};
