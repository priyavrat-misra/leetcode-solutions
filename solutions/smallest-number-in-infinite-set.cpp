class SmallestInfiniteSet {
public:
    set<int> integers;
    int currentInt;
    SmallestInfiniteSet() {
        currentInt = 1;
    }
    
    int popSmallest() {
        int ans;
        if (!integers.empty()) {
            ans = *integers.begin();
            integers.erase(integers.begin());
        } else {
            ans = currentInt;
            ++currentInt;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (currentInt <= num || integers.count(num))
            return;
        integers.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
