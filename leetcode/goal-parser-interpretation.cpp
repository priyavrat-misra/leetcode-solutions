class Solution {
public:
    string interpret(string& command) {
        string out;
        string::iterator begin = command.begin(), end = command.end();
        while (begin < end) {
            if (*begin == 'G') {
                out += 'G';
                ++begin;
            }
            else {
                ++begin;
                if (*begin == ')') {
                    out += 'o';
                    ++begin;
                } else {
                    out += "al";
                    begin += 3;
                }
            }
        }
        return out;
    }
};
