class TrieNode {
public:
    TrieNode* next[26]{nullptr};
    bool isWord = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* t = root;
        for (char& c : word) {
            if (!t -> next[c - 'a'])
                t -> next[c - 'a'] = new TrieNode();
            t = t -> next[c - 'a'];
        }
        t -> isWord = true;
    }
    
    bool search(string word) {
        TrieNode* t = root;
        for (int i = 0; i < word.size() && t; ++i)
            t = t -> next[word[i] - 'a'];
        return t && t -> isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for (int i = 0; i < prefix.size() && t; ++i)
            t = t -> next[prefix[i] - 'a'];
        return t;
    }

    void del(TrieNode* root) {
        if (root) {
            for (int i = 0; i < 26; ++i)
                if (root -> next[i])
                    del(root -> next[i]);
            delete root;
        }
    }

    ~Trie() {
        del(root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */