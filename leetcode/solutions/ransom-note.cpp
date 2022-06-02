class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for (const char& c : magazine)
            ++freq[c - 'a'];
        for (const char& c : ransomNote)
            if (--freq[c - 'a'] < 0)
                return false;
        
        return true;
    }
};
