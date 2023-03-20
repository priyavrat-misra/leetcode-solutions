class BrowserHistory {
public:
    int curr = 0;
    vector<string> history;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        int n = history.size() - 1;
        while (curr != n)
            history.pop_back(), --n;
        history.push_back(url);
        ++curr;
    }
    
    string back(int steps) {
        if (steps > curr)
            curr = 0;
        else
            curr -= steps;
        return history[curr];
    }
    
    string forward(int steps) {
        if (steps + curr >= history.size())
            curr = history.size() - 1;
        else
            curr += steps;
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */