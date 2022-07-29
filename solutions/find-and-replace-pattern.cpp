class Solution {
public:
    bool match(string& word, string& pattern) {
	unordered_map<char, char> w2p, p2w;
	for(int i = 0; i < word.size(); ++i) 
		if(w2p.count(word[i]) && w2p[word[i]] != pattern[i]
		|| p2w.count(pattern[i]) && p2w[pattern[i]] != word[i]) 
			return false;
		else
			w2p[word[i]] = pattern[i],
			p2w[pattern[i]] = word[i];
        
	return true;
}
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string& word : words)
            if (match(word, pattern))
                res.push_back(word);
        
        return res;
    }
};
