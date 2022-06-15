class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1)
            return {strs};
        
        unordered_map<string, vector<string>> hash_table;
        for (string& str : strs) {
            vector<int> freq(26);
            for (char& c : str)
                ++freq[c-'a'];
            
            string hash_val;
            for (int& f : freq)
                hash_val += f + '0';
            hash_table[hash_val].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& row : hash_table)
            ans.push_back(row.second);
        
        return ans;
    }
};
