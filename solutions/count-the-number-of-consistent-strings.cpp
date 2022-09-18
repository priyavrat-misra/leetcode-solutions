class Solution {
public:
    int countConsistentStrings(string& allowed, vector<string>& words) {
        int freq = 0;
        for (char& c : allowed)
            freq |= 1 << (c - 'a');
        
        int ans = words.size();
        for (string& word : words)
            for (char& c : word)
                if (!(freq & 1 << (c - 'a'))) {
                    --ans;
                    break;
                }
        
        return ans;
    }
};
