class TrieNode {
public:
    TrieNode* next[26]{nullptr};
    bool isWord = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* t = root;
        for (char& c : word) {
            if (!t -> next[c - 'a'])
                t -> next[c - 'a'] = new TrieNode();
            t = t -> next[c - 'a'];
        }
        t -> isWord = true;
    }

    bool search(string word) {
        return search(word.c_str(), root);
    }
    
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; ++i) {
            if (word[i] == '.') {
                TrieNode* t = node;
                for (int j = 0; j < 26; ++j) {
                    node = t -> next[j];
                    if (search(word + i + 1, node))
                        return true;
                }
            } else
                node = node -> next[word[i] - 'a'];
        }
        return node && node -> isWord;
    }

    void del(TrieNode* root) {
        if (root) {
            for (int i = 0; i < 26; ++i)
                if (root -> next[i])
                    del(root -> next[i]);
            delete root;
        }
    }

    ~WordDictionary() {
        del(root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */