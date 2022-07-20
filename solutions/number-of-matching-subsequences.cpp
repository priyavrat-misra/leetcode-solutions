class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        int ans = 0;
        vector<vector<int>> mappings(26);
        for(int i = 0; i < s.size(); ++i)
            mappings[s[i]-'a'].push_back(i);
        
        for (string& word : words) {
            bool found = true;
            for (int i = 0, prev = -1; found && i < word.size(); ++i) {
                vector<int>& v = mappings[word[i]-'a'];
                vector<int>::iterator it = upper_bound(v.begin(), v.end(), prev);
                if (it == v.end())
                    found = false;
                else
                    prev = *it;
            }
            ans += found;
        }
        return ans;
    }
};
