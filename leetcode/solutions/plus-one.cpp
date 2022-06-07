class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        if (digits[i] < 9)
            ++digits[i];
        else {
            while (i && digits[i] == 9)
                digits[i--] = 0;
            if (digits[i] == 9) {
                digits[i] = 1;
                digits.push_back(0);
            } else
                ++digits[i];
        }
        return digits;
    }
};
