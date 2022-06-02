class Solution {
public:
    bool isAlienSorted(vector<string>& words, string& order) {
        if (words.size() == 1)
            return true;
        
        vector<int> v(26);
        int pos = 0;
        for (char& c : order)
            v[c-'a'] = pos++;
        
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words[i+1].size())
                    return false;
                
                if (words[i][j] != words[i+1][j]) {
                    if (v[words[i][j]-'a'] > v[words[i+1][j]-'a'])
                        return false;
                    else
                        break;
                }
            }
        }
        return true;
    }
};
