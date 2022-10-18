class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string s = countAndSay(n - 1);
        string say;
        int count = 0;
        char curr = s[0];
        for (char& c : s) {
            if (curr == c) {
                ++count;
            } else {
                say += to_string(count);
                say += curr;
                curr = c;
                count = 1;
            }
        }
        say += to_string(count);
        say += curr;
        return say;
    }
};

