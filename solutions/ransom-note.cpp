class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]{0};
        for (char& c : magazine)
            ++freq[c-'a'];
        
        for (char& c : ransomNote)
            if (!freq[c-'a']--)
                return false;
        
        return true;
    }
};
