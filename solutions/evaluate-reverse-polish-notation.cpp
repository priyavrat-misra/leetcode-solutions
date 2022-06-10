class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int i;
        char s = '0';
        for (string& token : tokens) {
            switch (token[0]) {
                case '+':
                    i = stk.top();
                    stk.pop();
                    stk.top() += i;
                    break;
                case '*':
                    i = stk.top();
                    stk.pop();
                    stk.top() *= i;
                    break;
                case '/':
                    i = stk.top();
                    stk.pop();
                    stk.top() /= i;
                    break;
                case '-':
                    if (token.size() == 1) {
                        i = stk.top();
                        stk.pop();
                        stk.top() -= i;
                        break;
                    }
                    s = token[0];
                    token[0] = '0';
                default:
                    i = 0;
                    for (char& c : token)
                        i = i * 10 + (c - '0');
                    s == '-' ? stk.push(-i) : stk.push(i);
                    s = '0';
                    break;
            }
        }
        return stk.top();
    }
};
