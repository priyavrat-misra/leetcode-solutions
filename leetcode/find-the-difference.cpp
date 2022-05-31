class Solution {
public:
    char findTheDifference(string& s, string& t) {
        char ch = 0;
        s += t;
        for (const char& c : s)
            ch ^= c;
        return ch;
    }
};
