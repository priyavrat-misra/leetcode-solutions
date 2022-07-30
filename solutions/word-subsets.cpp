class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> m(26);
        for (string& word : words2) {
            vector<int> ccnt(26);
            for (char& c : word)
                ++ccnt[c-'a'];
            
            for (int i = 0; i < 26; ++i)
                m[i] = max(m[i], ccnt[i]);
        }
        
        vector<string> res;
        for (string& word : words1) {
            vector<int> ccnt(26);
            for (char& c : word)
                ++ccnt[c-'a'];
            
            bool valid = true;
            for (int i = 0; i < 26; ++i)
                if (m[i] > ccnt[i]) {
                    valid = false;
                    break;
                }
            
            if (valid)
                res.push_back(word);
        }
        return res;
    }
};
