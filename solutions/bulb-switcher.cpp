class Solution {
public:
    int bulbSwitch(int n) {
        int i = 1;
        while (i * i <= n)
            ++i;
        return i - 1;
    }
};
