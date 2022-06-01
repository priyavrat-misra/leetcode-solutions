class Solution {
public:
    string toLowerCase(string& s) {
        for (char& c : s)
            if (c > 64 && c < 91)
                c += 32;
        return s;
    }
};
