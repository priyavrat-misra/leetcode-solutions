class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = 0, prefixVal = 0;
        for (int& num : nums) {
            prefixVal += num;
            minVal = min(minVal, prefixVal);
        }
        return -minVal + 1;
    }
};
