class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (string& word : words)
            ++m[word];
        int n = words.size();
        vector<vector<string>> bucket(n);
        for (auto& r : m)
            bucket[r.second].push_back(r.first);
        vector<string> res;
        for (int i = n - 1; k > 0 && i >= 0; i--) {
            if (bucket[i].empty())
                continue;
            int n = min(k, (int) bucket[i].size());
            res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + n);
            k -= n;
        }
        return res;
    }
};
