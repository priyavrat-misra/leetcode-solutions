class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {}
    
    bool insert(int val) {  // O(1)
        return s.insert(val).second;
    }
    
    bool remove(int val) {  // O(1)
        return s.erase(val);
    }
    
    int getRandom() {  // O(n)
        auto it = s.begin();
        int val = rand() % s.size();
        while (val--)
            ++it;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
