class Solution {
public:
    vector<string> uncommonFromSentences(string& s1, string& s2) {
        unordered_map<string, int> map;
        istringstream ss1(s1), ss2(s2);
        string word;
        while (getline(ss1, word, ' '))
            ++map[word];
        
        while (getline(ss2, word, ' '))
            ++map[word];
        
        vector<string> ans;
        for (pair<const string, int>& row : map)
            if (row.second == 1)
                ans.push_back(row.first);
        
        return ans;
    }
};
