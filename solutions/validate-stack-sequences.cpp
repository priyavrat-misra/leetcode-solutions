class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size(), j = 0;
        for (int& i : pushed) {
            stk.push(i);
            while (j < n && !stk.empty() && stk.top() == popped[j])
                stk.pop(), ++j;
        }
        return j == n;
    }
};
